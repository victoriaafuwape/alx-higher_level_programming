#!/usr/bin/python3
class LockedClass:
    """
    A class that only allows creating an instance attribute named 'first_name'.
    """
    def __setattr__(self, name, value):
        if name != "first_name":
            raise AttributeError("'LockedClass' object has no attribute '"
                                 + name + "'")
        self.__dict__[name] = value
