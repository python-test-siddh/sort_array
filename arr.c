#include <stdio.h>
#include <Python.h>

// wrapper function for moku
static PyObject *Moku(PyObject *self, PyObject *args) {
    PyObject *lst;
    if (!PyArg_ParseTuple(args, "O", &lst)) {
        return NULL;
    }

    int n = PyObject_Length(lst);
    if (n < 0) 
    {
        return NULL;
    }

    long nums[n];
    for (int i = 0; i < n; i++) {
        PyLongObject *item = PyList_GetItem(lst, i);
        long num = PyLong_AsLong(item);
        nums[i] = num;
    }

    unsigned long fact_sum;
    fact_sum = ifactorial_sum(nums, n);

    return Py_BuildValue("i", fact_sum);
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
