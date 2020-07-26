#include "Python.h"
#include "pasLib.h"
#include "stdio.h"
#include "string.h"
#include <iostream>
//Python interface

static PyObject* pasLib_TestFunction(PyObject *self, PyObject *args)
{
	PyObject* output = Py_BuildValue("(iii)", 1, 2, 3);
	pasLib::TestFunction();
	return output;
}

static PyObject* pasLib_CreateNewGraphicsWindow(PyObject *self, PyObject *args)
{
	const char* filename;
	if (!PyArg_ParseTuple(args, "s", &filename)) {return NULL;}
	std::string fnamestr(filename);
	pasLib::NewGraphicsWindow(fnamestr);
	return Py_BuildValue("");
}


static PyMethodDef pasLibMethods[] =
{
	{"TestFunction", pasLib_TestFunction, METH_VARARGS, "A test function."},
	{"CreateNewGraphicsWindow", pasLib_CreateNewGraphicsWindow, METH_VARARGS, "Create new graphics window."},
	{NULL, NULL, 0, NULL}        /* Sentinel */
};

static struct PyModuleDef pasLib_ModuleDef =
{
    PyModuleDef_HEAD_INIT,
    "pasLib",
    "",
    -1,
    pasLibMethods
};



PyMODINIT_FUNC PyInit_pasLib(void)
{
	return PyModule_Create(&pasLib_ModuleDef);
}
