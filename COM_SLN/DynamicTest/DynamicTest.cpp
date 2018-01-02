// DynamicTest.cpp : Defines the entry point for the console application.
//

#include <tchar.h>
#include <Windows.h>
#include <iostream>

#include "Iface.h"
#pragma comment(lib,"../Debug/DynamicCOM.lib")

typedef IUnknown *(*CREATEFUNCPTR)();

IUnknown * CallCreateInstance()
{
	HINSTANCE hInstLibrary = LoadLibrary(L"../Debug/DynamicCOM.dll");
	if (hInstLibrary == NULL)
		FreeLibrary(hInstLibrary);

	CREATEFUNCPTR dllFunc = (CREATEFUNCPTR)GetProcAddress(hInstLibrary, "CreateInstance");
	if (dllFunc == NULL)
		FreeLibrary(hInstLibrary);

	return dllFunc();
}

void trace(const char *msg){ std::cout << msg << std::endl; }

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr = NULL;

	trace("Client: Get an IUnknow pointer");
	IUnknown *pIUnknow = CallCreateInstance();

	trace("Client: Get interface IX");
	IX * pIX = NULL;
	hr = pIUnknow->QueryInterface(IID_IX, (void **)&pIX);
	if (SUCCEEDED(hr))
	{
		trace("Client: Succeeded getting IX");
		pIX->Fx();
		pIX->Release();
	}

	trace("Client: Get interface IY");
	IY *pIY = NULL;
	hr = pIUnknow->QueryInterface(IID_IY, (void **)&pIY);
	if (SUCCEEDED(hr))
	{
		trace("Client: Succeeded getting IY");
		pIY->Fy();
		pIY->Release();
	}

	trace("Client: Ask for an unsupported interface");
	IZ *pIZ = NULL;
	hr = pIUnknow->QueryInterface(IID_IZ, (void **)&pIZ);
	if (SUCCEEDED(hr))
	{
		trace("Client: Succeeded getting IZ");
		pIZ->Fz();
		pIZ->Release();
	}
	else
	{
		trace("Client: Could not get interface IZ");
	}

	trace("Client: Release IUnknow interface");
	pIUnknow->Release();
	return 0;
}

