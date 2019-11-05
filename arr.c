#include <stdio.h>
#include <Python.h>

// wrapper function for moku
static PyObject *Moku(PyObject *self, PyObject *args) 
{
    
    
    return Py_BuildValue("moku Loaded");
}

// module's function table
static PyMethodDef DemoLib_FunctionsTable[] = {
    {
        "moku", // name exposed to Python
        Moku, // C wrapper function
        METH_VARARGS, // received variable args (but really just 1)
        "Calculates factorial sum from digits in string of numbers" // documentation
    }, {
        NULL, NULL, 0, NULL
    }
};

// modules definition
static struct PyModuleDef DemoLib_Module = {
    PyModuleDef_HEAD_INIT,
    "moku",     // name of module exposed to Python
    "Demo Python wrapper for custom C extension library.", // module documentation
    -1,
    DemoLib_FunctionsTable
};

PyMODINIT_FUNC PyInit_demo(void) {
    return PyModule_Create(&DemoLib_Module);
}
