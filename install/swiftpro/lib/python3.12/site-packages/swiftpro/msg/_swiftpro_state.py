# generated from rosidl_generator_py/resource/_idl.py.em
# with input from swiftpro:msg/SwiftproState.idl
# generated code does not contain a copyright notice

# This is being done at the module level and not on the instance level to avoid looking
# for the same variable multiple times on each instance. This variable is not supposed to
# change during runtime so it makes sense to only look for it once.
from os import getenv

ros_python_check_fields = getenv('ROS_PYTHON_CHECK_FIELDS', default='')


# Import statements for member types

import builtins  # noqa: E402, I100

import math  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_SwiftproState(type):
    """Metaclass of message 'SwiftproState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('swiftpro')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'swiftpro.msg.SwiftproState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__swiftpro_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__swiftpro_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__swiftpro_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__swiftpro_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__swiftpro_state

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class SwiftproState(metaclass=Metaclass_SwiftproState):
    """Message class 'SwiftproState'."""

    __slots__ = [
        '_motor_angle1',
        '_motor_angle2',
        '_motor_angle3',
        '_motor_angle4',
        '_x',
        '_y',
        '_z',
        '_pump',
        '_swiftpro_status',
        '_gripper',
        '_limit_switch',
        '_check_fields',
    ]

    _fields_and_field_types = {
        'motor_angle1': 'double',
        'motor_angle2': 'double',
        'motor_angle3': 'double',
        'motor_angle4': 'double',
        'x': 'double',
        'y': 'double',
        'z': 'double',
        'pump': 'uint8',
        'swiftpro_status': 'uint8',
        'gripper': 'uint8',
        'limit_switch': 'uint8',
    }

    # This attribute is used to store an rosidl_parser.definition variable
    # related to the data type of each of the components the message.
    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        if 'check_fields' in kwargs:
            self._check_fields = kwargs['check_fields']
        else:
            self._check_fields = ros_python_check_fields == '1'
        if self._check_fields:
            assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
                'Invalid arguments passed to constructor: %s' % \
                ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.motor_angle1 = kwargs.get('motor_angle1', float())
        self.motor_angle2 = kwargs.get('motor_angle2', float())
        self.motor_angle3 = kwargs.get('motor_angle3', float())
        self.motor_angle4 = kwargs.get('motor_angle4', float())
        self.x = kwargs.get('x', float())
        self.y = kwargs.get('y', float())
        self.z = kwargs.get('z', float())
        self.pump = kwargs.get('pump', int())
        self.swiftpro_status = kwargs.get('swiftpro_status', int())
        self.gripper = kwargs.get('gripper', int())
        self.limit_switch = kwargs.get('limit_switch', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.get_fields_and_field_types().keys(), self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    if self._check_fields:
                        assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.motor_angle1 != other.motor_angle1:
            return False
        if self.motor_angle2 != other.motor_angle2:
            return False
        if self.motor_angle3 != other.motor_angle3:
            return False
        if self.motor_angle4 != other.motor_angle4:
            return False
        if self.x != other.x:
            return False
        if self.y != other.y:
            return False
        if self.z != other.z:
            return False
        if self.pump != other.pump:
            return False
        if self.swiftpro_status != other.swiftpro_status:
            return False
        if self.gripper != other.gripper:
            return False
        if self.limit_switch != other.limit_switch:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def motor_angle1(self):
        """Message field 'motor_angle1'."""
        return self._motor_angle1

    @motor_angle1.setter
    def motor_angle1(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor_angle1' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'motor_angle1' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._motor_angle1 = value

    @builtins.property
    def motor_angle2(self):
        """Message field 'motor_angle2'."""
        return self._motor_angle2

    @motor_angle2.setter
    def motor_angle2(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor_angle2' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'motor_angle2' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._motor_angle2 = value

    @builtins.property
    def motor_angle3(self):
        """Message field 'motor_angle3'."""
        return self._motor_angle3

    @motor_angle3.setter
    def motor_angle3(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor_angle3' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'motor_angle3' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._motor_angle3 = value

    @builtins.property
    def motor_angle4(self):
        """Message field 'motor_angle4'."""
        return self._motor_angle4

    @motor_angle4.setter
    def motor_angle4(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'motor_angle4' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'motor_angle4' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._motor_angle4 = value

    @builtins.property
    def x(self):
        """Message field 'x'."""
        return self._x

    @x.setter
    def x(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'x' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'x' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._x = value

    @builtins.property
    def y(self):
        """Message field 'y'."""
        return self._y

    @y.setter
    def y(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'y' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'y' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._y = value

    @builtins.property
    def z(self):
        """Message field 'z'."""
        return self._z

    @z.setter
    def z(self, value):
        if self._check_fields:
            assert \
                isinstance(value, float), \
                "The 'z' field must be of type 'float'"
            assert not (value < -1.7976931348623157e+308 or value > 1.7976931348623157e+308) or math.isinf(value), \
                "The 'z' field must be a double in [-1.7976931348623157e+308, 1.7976931348623157e+308]"
        self._z = value

    @builtins.property
    def pump(self):
        """Message field 'pump'."""
        return self._pump

    @pump.setter
    def pump(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'pump' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'pump' field must be an unsigned integer in [0, 255]"
        self._pump = value

    @builtins.property
    def swiftpro_status(self):
        """Message field 'swiftpro_status'."""
        return self._swiftpro_status

    @swiftpro_status.setter
    def swiftpro_status(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'swiftpro_status' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'swiftpro_status' field must be an unsigned integer in [0, 255]"
        self._swiftpro_status = value

    @builtins.property
    def gripper(self):
        """Message field 'gripper'."""
        return self._gripper

    @gripper.setter
    def gripper(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'gripper' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gripper' field must be an unsigned integer in [0, 255]"
        self._gripper = value

    @builtins.property
    def limit_switch(self):
        """Message field 'limit_switch'."""
        return self._limit_switch

    @limit_switch.setter
    def limit_switch(self, value):
        if self._check_fields:
            assert \
                isinstance(value, int), \
                "The 'limit_switch' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'limit_switch' field must be an unsigned integer in [0, 255]"
        self._limit_switch = value
