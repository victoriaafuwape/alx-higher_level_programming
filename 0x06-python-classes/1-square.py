#!/usr/bin/python3

"""Module 1-square with class Square that defines a square."""


class Square:
    """A class Square that defines a square.

    Attributes:
        __size (int): The size of the square.
    """

    def __init__(self, size):
        """Initialize a new Square.

        Args:
            size (int): The size of the square.
        """
        self.__size = size
