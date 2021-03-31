#include <Python.h>
void print_python_string(PyObject *p)
{
	
	printf("[.] string object info\n");
	
	if(!PyUnicode_Check(p))
	{
		printf(" [ERROR] Invalid String Object\n");
		return;
	}
	if (PyUnicode_IS_COMPACT_ASCII(p))
		printf("  type: compact ascii\n");
	if (PyUnicode_IS_COMPACT(p) && !PyUnicode_IS_ASCII(p))
                printf("  type: compact unicode object\n");
	if (PyUnicode_KIND(p) == PyUnicode_WCHAR_KIND)
                printf("  type: legacy string, not ready\n");
	if (!PyUnicode_IS_COMPACT(p) && PyUnicode_KIND(p) != PyUnicode_WCHAR_KIND)
                printf("  type: legacy string, not ready\n");
	printf("  length: %ld\n", ((PyASCIIObject *)(p))->length);
	printf("  value: %ls\n", PyUnicode_AsWideCharString(p, '\0'));	
}
