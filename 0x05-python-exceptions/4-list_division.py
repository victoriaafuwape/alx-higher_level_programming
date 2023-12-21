#!/usr/bin/python3
def list_division(my_list_1, my_list_2, list_length):
    result = []

    for i in range(list_length):
        try:
            # Check if the index is out of range for either list
            if i >= len(my_list_1) or i >= len(my_list_2):
                raise IndexError

            element_1 = my_list_1[i]
            element_2 = my_list_2[i]

            division_result = element_1 / element_2
            result.append(division_result)

        except ZeroDivisionError:
            print("division by 0")
            result.append(0)

        except (TypeError, ValueError):
            print("wrong type")
            result.append(0)

        except IndexError:
            print("out of range")
            result.append(0)

        finally:
            pass

    return result
