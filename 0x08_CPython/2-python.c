#include "Python.h"
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;

	if (!PyBytes_Check(p))
	{
		printf("  [ERROR] Invalid Bytes Object\n");
		return;
	}
	char *val = ((PyBytesObject *)p)->ob_sval;

	size = PyBytes_Size(p);
	printf("[.] bytes object info\n");
	printf("  size: %ld\n", size);
	printf("  trying string: %s\n", val);
	size = size > 9 ?  10 : size + 1;
	printf("  first %ld bytes:", size);
	for (i = 0; i < size; i++)
	{
		printf(" %02hhx", val[i]);
		/*printf("trying string: %s\n", PyList_GetItem(p,i));*/
		/*printf("Element %ld: %s\n",i, Py_TYPE(PyList_GetItem(p,i))->tp_name);*/
	}
	printf("\n");
}
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;

	size = Py_SIZE(p);
	printf("[*] Python list info\n");
	printf("[*] Size of the Python List = %ld\n", size);
	printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);
	for (i = 0; i < size; i++)
	{
		printf("Element %ld: %s\n", i, Py_TYPE(PyList_GetItem(p, i))->tp_name);
		if (PyBytes_Check((PyList_GetItem(p, i))))
			print_python_bytes((PyList_GetItem(p, i)));
	}
}

