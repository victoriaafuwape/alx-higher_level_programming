#!/usr/bin/python3

"""Module 100-singly_linked_list with classes Node and SinglyLinkedList."""


class Node:
    """A class Node that defines a node of a singly linked list."""

    def __init__(self, data, next_node=None):
        """Initialize a new Node.

        Args:
            data: Data stored in the node.
            next_node: The next node in the linked list.
        """
        self.data = data
        self.next_node = next_node

    @property
    def data(self):
        """Retrieve the data of the node."""
        return self.__data

    @data.setter
    def data(self, value):
        """Set the data of the node.

        Args:
            value: The new data of the node.

        Raises:
            TypeError: If value is not an integer.
        """
        if not isinstance(value, int):
            raise TypeError("data must be an integer")
        self.__data = value

    @property
    def next_node(self):
        """Retrieve the next node in the linked list."""
        return self.__next_node

    @next_node.setter
    def next_node(self, value):
        """Set the next node in the linked list.

        Args:
            value: The new next node.

        Raises:
            TypeError: If next_node is not a Node object and not None.
        """
        if not isinstance(value, Node) and value is not None:
            raise TypeError("next_node must be a Node object")
        self.__next_node = value


class SinglyLinkedList:
    """A class SinglyLinkedList that defines a singly linked list."""

    def __init__(self):
        """Initialize a new SinglyLinkedList."""
        self.__head = None

    def sorted_insert(self, value):
        """Insert a new Node into the correct sorted position in the list."""
        new_node = Node(value)
        if self.__head is None or self.__head.data >= value:
            new_node.next_node = self.__head
            self.__head = new_node
        else:
            current = self.__head
            while current.next_node is not None and current.next_node.data < value:
                current = current.next_node
            new_node.next_node = current.next_node
            current.next_node = new_node

    def __str__(self):
        """Define the print() representation of the SinglyLinkedList."""
        values = []
        current = self.__head
        while current:
            values.append(str(current.data))
            current = current.next_node
        return "\n".join(values)
