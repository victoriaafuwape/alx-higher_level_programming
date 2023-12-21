#include "main.h"

void print_python_float(PyObject *p)
{
    double val = PyFloat_AsDouble(p);

    printf("[.] float object info\n");
    printf("  value: %g\n", val);
}

/**
 * print_python_list - Prints basic info about Python lists
 * @p: PyObject pointer to the Python list
 */
void print_python_list(PyObject *p)
{
    PyListObject *list = (PyListObject *)p;
    Py_ssize_t i;
    PyObject *item;

    if (!PyList_Check(p)) {
        printf("[ERROR] Invalid List Object\n");
        return;
    }

    printf("[*] Python list info\n");
    printf("[*] Size of the Python List = %zd\n", list->ob_base.ob_size);
    printf("[*] Allocated = %zd\n", list->allocated);

    for (i = 0; i < list->ob_base.ob_size; i++) {
        item = list->ob_item[i];
        printf("Element %zd: ", i);
        if (PyBytes_Check(item)) {
            printf("bytes\n");
            print_python_bytes(item);
        } else if (PyLong_Check(item)) {
            printf("int\n");
        } else if (PyFloat_Check(item)) {
            printf("float\n");
            print_python_float(item);
        } else if (PyTuple_Check(item)) {
            printf("tuple\n");
        } else if (PyList_Check(item)) {
            printf("list\n");
        } else if (PyUnicode_Check(item)) {
            printf("str\n");
        } else {
            printf("unknown\n");
        }
    }
}

/**
 * print_python_bytes - Prints basic info about Python bytes objects
 * @p: PyObject pointer to the Python bytes object
 */
void print_python_bytes(PyObject *p)
{
	Py_buffer view;
	int bytes_to_print, i;

	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}
	if (PyObject_GetBuffer(p, &view, PyBUF_SIMPLE) != 0)
	{
		PyErr_Clear();
		printf("  [ERROR] Failed to get buffer from bytes object\n");
		return;
	}
	printf("[.] bytes object info\n");
	printf("  size: %zd\n", view.len);
	printf("  trying string: %.*s\n", (int)view.len, (char *)view.buf);

	bytes_to_print = view.len < 10 ? view.len + 1 : 10;
	printf("  first %d bytes: ", bytes_to_print);
	for (i = 0; i < bytes_to_print - 1; ++i)
	{
		printf("%02x ", (unsigned char)(((char *)view.buf)[i]));
	}
	if (view.len < 10)
	{
		printf("00");
	}
	else if (view.len == 10)
	{
		printf("%02x", (unsigned char)(((char *)view.buf)[9]));
	}
	printf("\n");
	PyBuffer_Release(&view);
}

/**
 * print_python_float - Prints basic info about Python float objects
 * @p: PyObject pointer to the Python float object
 */
void print_python_float(PyObject *p)
{
	if (!PyFloat_Check(p))
	{
		printf("[ERROR] Invalid Float Object\n");
		return;
	}
}
