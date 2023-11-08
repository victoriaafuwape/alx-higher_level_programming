#include <Python.h>
#include <stdio.h>
/**
 * print_python_bytes - Prints basic info about Python bytes objects
 * @python_obj: PyObject pointer to a Python bytes object
 *
 * If python_obj is not a valid PyBytesObject, print an error message.
 */
void print_python_bytes(PyObject *python_obj) {
    long size_of_bytes;
    long index;
    long print_limit;
    char *bytes_content;

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(python_obj)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    size_of_bytes = PyBytes_Size(python_obj);
    bytes_content = PyBytes_AsString(python_obj);

    printf("  size: %ld\n", size_of_bytes);
    printf("  trying string: %s\n", bytes_content);

    print_limit = size_of_bytes < 10 ? size_of_bytes + 1 : 10;

    printf("  first %ld bytes:", print_limit);
    for (index = 0; index < print_limit; index++) {
        printf(" %02x", (unsigned char)bytes_content[index]);
    }
    printf("\n");
}

/**
 * print_python_list - Prints basic info about Python list objects
 * @python_obj: PyObject pointer to a Python list object
 *
 * If python_obj is not a valid PyListObject, print an error message.
 */
void print_python_list(PyObject *python_obj)
{
	long list_size;
	long index;
	PyObject *item;

	printf("[*] Python list info\n");
	if (!PyList_Check(python_obj))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}

	list_size = PyList_Size(python_obj);

	printf("[*] Size of the Python List = %ld\n", list_size);
	for (index = 0; index < list_size; index++)
	{
		item = PyList_GetItem(python_obj, index);
		printf("Element %ld: %s\n", index, Py_TYPE(item)->tp_name);

		if (PyBytes_Check(item))
		{
			print_python_bytes(item);
		}
	}
}
