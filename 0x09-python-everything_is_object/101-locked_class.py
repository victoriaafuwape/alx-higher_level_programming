#!/usr/bin/python3
class LockedClass:
    """
    A class that only allows creating an instance attribute named 'first_name'.
    """
    def __setattr__(self, name, value):
        if name == "first_name":
            self.__dict__[name] = value
        else:
            raise AttributeError(
                f"'LockedClass' object has no attribute '{name}'"
            )
