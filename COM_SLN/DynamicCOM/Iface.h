#ifndef IFACE_H
#define IFACE_H

#ifdef DLL_IMPLEMENT  
#define DLL_API extern "C" __declspec(dllexport)  
#else  
#define DLL_API extern "C" __declspec(dllimport)  
#endif

#include <objbase.h>


DLL_API IUnknown * CreateInstance();

interface IX : IUnknown
{
	virtual void __stdcall Fx() = 0;
};
interface IY : IUnknown
{
	virtual void __stdcall Fy() = 0;
};
interface IZ : IUnknown
{
	virtual void __stdcall Fz() = 0;
};


const IID IID_IX = { 0x1eeb6bb0, 0x56d4, 0x4b5a, { 0xbb, 0x98, 0xe9, 0x4a, 0xde, 0x89, 0x2f, 0x7d } };
const IID IID_IY = { 0x20a4b62b, 0x5a98, 0x462d, { 0x9a, 0x32, 0x58, 0x4f, 0x57, 0xac, 0xa5, 0x8e } };
const IID IID_IZ = { 0x367c6b0f, 0x2e93, 0x493d, { 0xab, 0x54, 0x29, 0x7, 0x79, 0x7, 0xd8, 0xd3 } };

#endif