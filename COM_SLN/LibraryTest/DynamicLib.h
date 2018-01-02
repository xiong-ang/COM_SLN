#ifndef DYNAMICLIB_H
#define DYNAMICLIB_H

#ifdef DLL_IMPLEMENT  
#define DLL_API extern "C" __declspec(dllexport)  
#else  
#define DLL_API extern "C" __declspec(dllimport)  
#endif

DLL_API int Add(int a, int b);

#endif