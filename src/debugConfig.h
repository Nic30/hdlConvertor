#pragma once
#include <iostream>

#define USE_PYTHON

#ifdef USE_PYTHON
#include <Python.h>
#endif

//#define JSN_DEBUG(msg) std::cout<< msg <<std::endl;
#define JSN_DEBUG(msg)

//#define MOD_DEBUG(msg) std::cout<< msg <<std::endl;
#define MOD_DEBUG(msg)
