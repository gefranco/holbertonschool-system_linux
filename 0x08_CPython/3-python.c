#include "Python.h"

void print_python_float(PyObject *p)
{
	double val;

	setbuf(stdout, NULL);
	printf("[.] float object info\n");

	if (!PyFloat_Check(p))
	{
		printf("  [ERROR] Invalid Float Object\n");
		return;
	}
	/*if(((PyFloatObject *)(p))->ob_fval== (int)((PyFloatObject *)(p))->ob_fval)*/
	/*	printf("value: %.1f\n", ((PyFloatObject *)(p))->ob_fval);*/
	/*else*/
	/*	printf("  value: %.15g\n", ((PyFloatObject *)(p))->ob_fval);*/
	val = ((PyFloatObject *)(p))->ob_fval;
	printf("  value: %s\n",
	PyOS_double_to_string(val, 'r', 0, Py_DTSF_ADD_DOT_0, NULL));
}

void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;

	setbuf(stdout, NULL);
	printf("[.] bytes object info\n");
	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	char *val = ((PyBytesObject *)p)->ob_sval;

	size = ((PyVarObject *)(p))->ob_size;
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", val);
	size = size > 9 ?  10 : size + 1;
	printf("  first %ld bytes:", size);
	for (i = 0; i < size; i++)
	{
		printf(" %02hhx", val[i]);
	}
	printf("\n");
}
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;

	setbuf(stdout, NULL);
	if (!PyList_Check(p))
	{
		printf("  [ERROR] Invalid List Object\n");
		return;
	}
	size = ((PyVarObject *)(p))->ob_size;
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
	{
		printf("Element %ld: %s\n", i,
		((PyListObject *)p)->ob_item[i]->ob_type->tp_name);
		if (PyFloat_Check(((PyListObject *)p)->ob_item[i]))
			print_python_float(((PyListObject *)p)->ob_item[i]);
		else if (PyBytes_Check(((PyListObject *)p)->ob_item[i]))
			print_python_bytes(((PyListObject *)p)->ob_item[i]);
	}
}

