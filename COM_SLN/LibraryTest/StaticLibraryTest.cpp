#include "stdafx.h"

#include "StaticLib.h"
#pragma comment(lib, "../Debug/StaticLibrary.lib")

void StaticLibraryTest()
{
	std::cout << Add(50, 2) << std::endl;
}