#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>

/**
 * print_python_list - Prints basic info about Python lists
 * @p: PyObject list pointer
 */
void print_python_list(PyObject *p)
{
    Py_ssize_t size, alloc, i;
    PyObject *item;
    PyListObject *list = (PyListObject *)p;

    printf("[*] Python list info\n");

    if (PyList_Check(p))
    {
        size = PyList_GET_SIZE(p);
        alloc = list->allocated;

        printf("[*] Size of the Python List = %zd\n", size);
        printf("[*] Allocated = %zd\n", alloc);

        for (i = 0; i < size; i++)
        {
            item = PyList_GET_ITEM(p, i);
            printf("Element %zd: %s\n", i, Py_TYPE(item)->tp_name);
        }
    }
    else
    {
        printf("  [ERROR] Invalid List Object\n");
    }
}

/**
 * print_python_bytes - Prints basic info about Python bytes objects
 * @p: PyObject bytes pointer
 */
void print_python_bytes(PyObject *p)
{
    Py_ssize_t size, i;
    char *trying_str;

    printf("[.] bytes object info\n");

    if (PyBytes_Check(p))
    {
        size = PyBytes_Size(p);
        trying_str = PyBytes_AsString(p);

        printf("  size: %zd\n", size);
        printf("  trying string: %s\n", trying_str);
        printf("  first %zd bytes:", size < 10 ? size + 1 : 10);

        for (i = 0; i < size + 1 && i < 10; i++)
        {
            if (i > 0) printf(" ");
            printf("%02x", (unsigned char)trying_str[i]);
        }
        printf("\n");
    }
    else
    {
        printf("  [ERROR] Invalid Bytes Object\n");
    }
}
