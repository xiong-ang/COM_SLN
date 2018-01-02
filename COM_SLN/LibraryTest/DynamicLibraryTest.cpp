#include "stdafx.h"

#include "DynamicLib.h"
#pragma comment(lib,"../Debug/DynamicLibrary.lib")
typedef int(*DLLFunc)(int, int);

void DynamicLibraryTest()
{
	HINSTANCE hInstLibrary = LoadLibrary(L"../Debug/DynamicLibrary.dll");
	if (hInstLibrary == NULL)
		FreeLibrary(hInstLibrary);

	DLLFunc dllFunc = (DLLFunc)GetProcAddress(hInstLibrary, "Add");
	if (dllFunc == NULL)
		FreeLibrary(hInstLibrary);

	std::cout << dllFunc(123, 89) << std::endl;

	FreeLibrary(hInstLibrary);
}


