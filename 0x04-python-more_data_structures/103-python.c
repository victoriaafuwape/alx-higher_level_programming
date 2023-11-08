#include <Python.h>
#include <object.h>
#include <listobject.h>
#include <bytesobject.h>
#include <stdio.h>

void print_python_list(PyObject *p) {
    Py_ssize_t size, alloc, i;
    PyListObject *list;
    const char *type_name;

    printf("[*] Python list info\n");
    if (!PyList_Check(p)) {
        printf("  [ERROR] Invalid List Object\n");
        return;
    }

    list = (PyListObject *)p;
    size = PyVarObject_HEAD_INIT(NULL, 0).ob_size;
    alloc = list->allocated;

    printf("[*] Size of the Python List = %zd\n", size);
    printf("[*] Allocated = %zd\n", alloc);

    for (i = 0; i < size; i++) {
        type_name = list->ob_item[i]->ob_type->tp_name;
        printf("Element %zd: %s\n", i, type_name);
        if (PyBytes_Check(list->ob_item[i])) {
            print_python_bytes(list->ob_item[i]);
        }
    }
}

void print_python_bytes(PyObject *p) {
    PyBytesObject *bytes;
    Py_ssize_t size, i;
    char *trying_str;  // Pointer to array of bytes

    printf("[.] bytes object info\n");
    if (!PyBytes_Check(p)) {
        printf("  [ERROR] Invalid Bytes Object\n");
        return;
    }

    bytes = (PyBytesObject *)p;
    size = Py_SIZE(p);
    trying_str = bytes->ob_sval;

    printf("  size: %zd\n", size);
    printf("  trying string: %s\n", trying_str);
    printf("  first %zd bytes: ", (size < 10 ? size + 1 : 10));

    for (i = 0; i < size && i < 10; i++) {
        printf("%02x", (unsigned char)trying_str[i]);
        if (i < 9) {
            printf(" ");
        }
    }

    if (size >= 10) {
        printf(" ...\n");
    } else {
        printf("\n");
    }
}
