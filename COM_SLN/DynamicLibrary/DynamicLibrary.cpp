// DynamicLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"

#define DLL_IMPLEMENT
#include "DynamicLib.h"


DLL_API int Add(int a, int b)
{
	return a + b;
}