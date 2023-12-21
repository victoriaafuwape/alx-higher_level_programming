#include "main.h"

/**
 * print_python_list - Prints basic info about Python lists
 * @p: PyObject pointer to the Python list
 */
void print_python_list(PyObject *p)
{
	if (!PyList_Check(p))
	{
		printf("[ERROR] Invalid List Object\n");
		return;
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

	printf("  first 10 bytes: ");
	bytes_to_print = view.len < 10 ? view.len : 10;
	for (i = 0; i < bytes_to_print; ++i)
	{
		printf("%02x ", (unsigned char)(((char *)view.buf)[i]));
		if (i < 9)
		{
			printf(" ");
		}
	}
	if (view.len < 10)
	{
		printf("00");
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
