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
	if (!PyBytes_Check(p))
	{
		printf("[ERROR] Invalid Bytes Object\n");
		return;
	}
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
