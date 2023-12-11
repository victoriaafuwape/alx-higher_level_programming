#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    """Divide two lists element by element"""
    new_list = []
    for i in range(list_length):
        try:
            element_1 = my_list_1[i] if i < len(my_list_1) else 0
            element_2 = my_list_2[i] if i < len(my_list_2) else 0

            division_result = element_1 / element_2
            new_list.append(division_result)

        except ZeroDivisionError:
            print("division by 0")
            new_list.append(0)

        except (TypeError, ValueError):
            print("wrong type")
            new_list.append(0)

    return new_list
