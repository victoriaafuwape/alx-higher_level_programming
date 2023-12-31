#!/usr/bin/python3

"""Module 103-magic_class demonstrating a class that mimics a circle's prop."""

import math


class MagicClass:
    """Represents a circle and allows calculation of its area and circum."""

    def __init__(self, radius=0):
        """Initialize the MagicClass with a given radius."""
        self.__validate_radius(radius)
        self.__radius = radius

    def __validate_radius(self, radius):
        """Validate that the radius is a number."""
        if type(radius) not in [int, float]:
            raise TypeError("radius must be a number")

    def area(self):
        """Calculate the area of the circle."""
        return self.__radius ** 2 * math.pi

    def circumference(self):
        """Calculate the circumference of the circle."""
        return 2 * math.pi * self.__radius
