// utils.h
// Contains helper functions

#include <cstdio>

#ifndef UTILS_H
#define UTILS_H
namespace Printing
{
	// Function for printing out the content of an array
	template<typename T>
	void PrintArr(T* pArrBeg, T* pArrEnd)
	{
		while (pArrBeg != pArrEnd)
		{
			std::cout << *pArrBeg++ << "; ";
		}
		std::puts("\n");
	}
} // Printing

#endif // UTILS_H