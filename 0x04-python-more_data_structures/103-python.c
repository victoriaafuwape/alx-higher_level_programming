#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

/**
 * print_python_bytes - Prints information about Python bytes objects
 * @p: Pointer to a Python object (PyObject)
 */
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, limit, i;
	char *str;

	printf("[.] bytes object info\n");
	if (PyBytes_Check(p))
	{
		size = ((PyBytesObject *)p)->ob_base.ob_size;
		str = ((PyBytesObject *)p)->ob_sval;
		printf("  size: %zd\n", size);
		printf("  trying string: %s\n", str);

		limit = size < 10 ? size + 1 : 10;
		printf("  first %zd bytes:", limit);
		for (i = 0; i < limit; ++i)
		{
			printf(" %02x", (unsigned char)str[i]);
		}
		printf("\n");
	}
	else
	{
		printf("  [ERROR] Invalid Bytes Object\n");
	}
}

/**
 * print_python_list - Prints information about Python list objects
 * @p: Pointer to a Python object (PyObject)
 */
void print_python_list(PyObject *p)
{
	Py_ssize_t size, allocated, i;
	PyListObject *list;
	PyObject *item;
	const char *type_name;

	printf("[*] Python list info\n");
	if (PyList_Check(p))
	{
		size = ((PyVarObject *)p)->ob_size;
		list = (PyListObject *)p;
		allocated = list->allocated;
		printf("[*] Size of the Python List = %zd\n", size);
		printf("[*] Allocated = %zd\n", allocated);

		for (i = 0; i < size; i++)
		{
			item = list->ob_item[i];
			type_name = item->ob_type->tp_name;
			printf("Element %zd: %s\n", i, type_name);
			if (PyBytes_Check(item))
			{
				print_python_bytes(item);
			}
		}
	}
	else
	{
		printf("  [ERROR] Invalid List Object\n");
	}
}
