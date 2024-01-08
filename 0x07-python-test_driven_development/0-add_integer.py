#!/usr/bin/python3

"""
This module contains functions for performing various mathematical operations.
"""


def add_integer(a, b=98):

    """
    Adds two numbers and returns the result as an integer.
    """

    if type(a) is not int or type(a) is not float:
        raise TypeError("a must be an integer")
    if type(b) is not int or type(b) is not float:
        raise TypeError("b must be an integer")

    result = int(a) + int(b)

    return result
