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


static PyObject* pasLib_InitGraphicsBuffer(PyObject *self, PyObject *args)
{
	int wid, hei;
	if (!PyArg_ParseTuple(args, "ii", &wid, &hei)) {return NULL;}
	pasLib::InitGraphicsBuffer(wid, hei);
	return Py_BuildValue("");
}

static PyObject* pasLib_OnDisplay(PyObject *self, PyObject *args)
{
	pasLib::OnDisplay();
	return Py_BuildValue("");
}


static PyMethodDef pasLibMethods[] =
{
	{"TestFunction", pasLib_TestFunction, METH_VARARGS, "A test function."},
	{"CreateNewGraphicsWindow", pasLib_CreateNewGraphicsWindow, METH_VARARGS, "Create new graphics window."},
	{"InitGraphicsBuffer", pasLib_InitGraphicsBuffer, METH_VARARGS, "Initialize the image pixel buffer."},
	{"OnDisplay", pasLib_OnDisplay, METH_VARARGS, "Renders current objects to the display buffer."},
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
