/*
 * serial_port.hpp – Lightweight POSIX serial helper
 * Replaces the ROS1 "serial" library for ROS2 compatibility.
 *
 * Copyright (c) 2017, UFactory, Inc.  (original driver)
 * ROS2 port: 2026
 */
#pragma once

#include <string>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <chrono>
#include <thread>

#include <fcntl.h>
#include <termios.h>
#include <unistd.h>
#include <sys/ioctl.h>

class SerialPort
{
public:
  SerialPort() = default;

  ~SerialPort()
  {
    close();
  }

  // ── configuration ────────────────────────────────────────────────
  void setPort(const std::string & port)     { port_ = port; }
  void setBaudrate(unsigned int baud)        { baud_ = baud; }
  void setTimeout(unsigned int timeout_ms)   { timeout_ms_ = timeout_ms; }

  // ── open / close ─────────────────────────────────────────────────
  void open()
  {
    fd_ = ::open(port_.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
    if (fd_ < 0)
      throw std::runtime_error("Unable to open port " + port_ + ": " + std::strerror(errno));

    // Remove O_NONBLOCK after open so reads can block up to timeout
    int flags = fcntl(fd_, F_GETFL, 0);
    fcntl(fd_, F_SETFL, flags & ~O_NONBLOCK);

    struct termios tty{};
    if (tcgetattr(fd_, &tty) != 0)
      throw std::runtime_error("tcgetattr failed: " + std::string(std::strerror(errno)));

    speed_t speed = baud_to_speed(baud_);
    cfsetispeed(&tty, speed);
    cfsetospeed(&tty, speed);

    // 8N1
    tty.c_cflag &= ~PARENB;
    tty.c_cflag &= ~CSTOPB;
    tty.c_cflag &= ~CSIZE;
    tty.c_cflag |= CS8;
    tty.c_cflag |= CREAD | CLOCAL;
    tty.c_cflag &= ~CRTSCTS;

    // Raw mode
    tty.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
    tty.c_iflag &= ~(IXON | IXOFF | IXANY | IGNBRK | BRKINT | PARMRK | ISTRIP | INLCR | IGNCR | ICRNL);
    tty.c_oflag &= ~OPOST;

    // Read timeout in deciseconds
    tty.c_cc[VMIN]  = 0;
    tty.c_cc[VTIME] = static_cast<cc_t>(timeout_ms_ / 100);
    if (tty.c_cc[VTIME] == 0) tty.c_cc[VTIME] = 1;  // minimum 100 ms

    if (tcsetattr(fd_, TCSANOW, &tty) != 0)
      throw std::runtime_error("tcsetattr failed: " + std::string(std::strerror(errno)));

    tcflush(fd_, TCIOFLUSH);
    is_open_ = true;
  }

  void close()
  {
    if (fd_ >= 0) {
      ::close(fd_);
      fd_ = -1;
      is_open_ = false;
    }
  }

  bool isOpen() const { return is_open_; }

  // ── I/O ──────────────────────────────────────────────────────────
  void write(const std::string & data)
  {
    if (fd_ < 0) return;
    ::write(fd_, data.c_str(), data.size());
  }

  std::string read(size_t max_bytes)
  {
    if (fd_ < 0) return {};
    std::string buf(max_bytes, '\0');
    ssize_t n = ::read(fd_, &buf[0], max_bytes);
    if (n <= 0) return {};
    buf.resize(static_cast<size_t>(n));
    return buf;
  }

  std::string readline(size_t max_bytes = 256, const std::string & eol = "\r\n")
  {
    if (fd_ < 0) return {};
    std::string result;
    result.reserve(max_bytes);
    auto start = std::chrono::steady_clock::now();

    while (result.size() < max_bytes) {
      char c;
      ssize_t n = ::read(fd_, &c, 1);
      if (n > 0) {
        result += c;
        if (result.size() >= eol.size() &&
            result.compare(result.size() - eol.size(), eol.size(), eol) == 0)
          break;
      } else {
        auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(
          std::chrono::steady_clock::now() - start).count();
        if (static_cast<unsigned int>(elapsed) >= timeout_ms_)
          break;
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
      }
    }
    return result;
  }

  size_t available()
  {
    if (fd_ < 0) return 0;
    int bytes = 0;
    ioctl(fd_, FIONREAD, &bytes);
    return static_cast<size_t>(bytes);
  }

  void flushInput()
  {
    if (fd_ >= 0) tcflush(fd_, TCIFLUSH);
  }

  void flushOutput()
  {
    if (fd_ >= 0) tcflush(fd_, TCOFLUSH);
  }

private:
  std::string  port_;
  unsigned int baud_       = 115200;
  unsigned int timeout_ms_ = 1000;
  int          fd_         = -1;
  bool         is_open_    = false;

  static speed_t baud_to_speed(unsigned int baud)
  {
    switch (baud) {
      case 9600:    return B9600;
      case 19200:   return B19200;
      case 38400:   return B38400;
      case 57600:   return B57600;
      case 115200:  return B115200;
      case 230400:  return B230400;
      case 460800:  return B460800;
      case 921600:  return B921600;
      default:      return B115200;
    }
  }
};
