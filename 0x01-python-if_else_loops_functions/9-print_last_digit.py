#!/usr/bin/python3

def print_last_digit(number):
    last_digit = abs(number) % 10  # Use abs to handle negative numbers
    print("{}".format(last_digit), end='')  # end='' prevents newline
    return last_digit
