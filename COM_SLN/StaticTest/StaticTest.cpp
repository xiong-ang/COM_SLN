// StaticTest.cpp : Defines the entry point for the console application.
//
#include <tchar.h>
#include "StaticCOM.h"
#pragma comment(lib, "../Debug/StaticCOM.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr = NULL;

	trace("Client: Get an IUnknow pointer");
	IUnknown *pIUnknow = CreateInstance();

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





/*
#include <iostream>
#include <objbase.h>

void trace(const char *msg){ std::cout << msg << std::endl; }

extern const IID IID_IX;
extern const IID IID_IY;
extern const IID IId_IZ;

interface IX :IUnknown
{
	virtual void __stdcall Fx() = 0;
};
interface IY :IUnknown
{
	virtual void __stdcall Fy() = 0;
};
interface IZ :IUnknown
{
	virtual void __stdcall Fz() = 0;
};

class CA :public IX, public IY
{
	virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	virtual void __stdcall Fx(){ std::cout << "Fx" << std::endl; }
	virtual void __stdcall Fy(){ std::cout << "Fy" << std::endl; }

public:
	CA() :m_cRef(0){}
	~CA(){}

private:
	long m_cRef;
};

HRESULT __stdcall CA::QueryInterface(const IID &iid, void **ppv)
{
	if (iid == IID_IUnknown)
	{
		trace("CA QI: Return pointer to IUknown");
		*ppv = static_cast<IX*>(this);
	}
	else if (iid == IID_IX)
	{
		trace("CA QI: Return pointer to IX");
		*ppv = static_cast<IX*>(this);
	}
	else if (iid == IID_IY)
	{
		trace("CA QI: Return pointer to IY");
		*ppv = static_cast<IY*>(this);
	}
	else
	{
		trace("CA QI: Interface not supported");
		*ppv = NULL;
		return E_NOINTERFACE;
	}
	reinterpret_cast<IUnknown*>(*ppv)->AddRef();
	return S_OK;
}

ULONG __stdcall CA::AddRef()
{
	std::cout << "CA: AddRef Ref = " << m_cRef + 1 << std::endl;
	return InterlockedIncrement(&m_cRef);
}

ULONG __stdcall CA::Release()
{
	std::cout << "CA: Release Ref = " << m_cRef - 1 << std::endl;
	if (InterlockedDecrement(&m_cRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_cRef;
}

IUnknown * CreateInstance()
{
	IUnknown *pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
}

const IID IID_IX = { 0x1eeb6bb0, 0x56d4, 0x4b5a, { 0xbb, 0x98, 0xe9, 0x4a, 0xde, 0x89, 0x2f, 0x7d } };
const IID IID_IY = { 0x20a4b62b, 0x5a98, 0x462d, { 0x9a, 0x32, 0x58, 0x4f, 0x57, 0xac, 0xa5, 0x8e } };
const IID IID_IZ = { 0x367c6b0f, 0x2e93, 0x493d, { 0xab, 0x54, 0x29, 0x7, 0x79, 0x7, 0xd8, 0xd3 } };

int _tmain(int argc, _TCHAR* argv[])
{
	HRESULT hr = NULL;

	trace("Client: Get an IUnknow pointer");
	IUnknown *pIUnknow = CreateInstance();

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
*/
