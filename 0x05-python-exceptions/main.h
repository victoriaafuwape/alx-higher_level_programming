#ifndef MAIN_H
#define MAIN_H

#include <Python.h>
#include <listobject.h>
#include <stdio.h>
#include <stdlib.h>

void print_python_float(PyObject *p);
void print_python_list(PyObject *p);
void print_python_bytes(PyObject *p);

#endif /* MAIN_H */
