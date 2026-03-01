// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from swiftpro:msg/Angle4th.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "swiftpro/msg/detail/angle4th__struct.h"
#include "swiftpro/msg/detail/angle4th__functions.h"


ROSIDL_GENERATOR_C_EXPORT
bool swiftpro__msg__angle4th__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[32];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("swiftpro.msg._angle4th.Angle4th", full_classname_dest, 31) == 0);
  }
  swiftpro__msg__Angle4th * ros_message = _ros_message;
  {  // angle4th
    PyObject * field = PyObject_GetAttrString(_pymsg, "angle4th");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->angle4th = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * swiftpro__msg__angle4th__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of Angle4th */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("swiftpro.msg._angle4th");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "Angle4th");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  swiftpro__msg__Angle4th * ros_message = (swiftpro__msg__Angle4th *)raw_ros_message;
  {  // angle4th
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->angle4th);
    {
      int rc = PyObject_SetAttrString(_pymessage, "angle4th", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
