#include "StaticCOM.h"

void trace(const char *msg){ std::cout << msg << std::endl; }


class CA :public IX, public IY
{
	virtual HRESULT __stdcall QueryInterface(const IID &iid, void **ppv);
	virtual ULONG __stdcall AddRef();
	virtual ULONG __stdcall Release();

	virtual void __stdcall Fx();
	virtual void __stdcall Fy();

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

void __stdcall CA::Fx(){ std::cout << "Fx" << std::endl; }
void __stdcall CA::Fy(){ std::cout << "Fy" << std::endl; }

IUnknown * CreateInstance()
{
	IUnknown *pI = static_cast<IX*>(new CA);
	pI->AddRef();
	return pI;
}