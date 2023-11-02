#!/usr/bin/python3
import sys


def main():
    sum = 0
    for arg in sys.argv[1:]:
        sum += int(arg)
    print(sum)


if __name__ == "__main__":
    main()
