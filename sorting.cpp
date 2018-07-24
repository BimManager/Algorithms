// sorting.cpp
// Sorting algorithms

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "sorting.h"
#include "utils.h"

#define SWAP(t, a, b) { t c = a; \
													a = b; \
													b = c; \
											}

namespace Sorting
{
	void insort(double* pArr, size_t cElems)
	{
		register size_t i, j;
		for (i = 1; i < cElems; ++i)
		{
			j = i - 1;
			while (j >= 0 && *(pArr + j) > *(pArr + j + 1))
			{
				SWAP(double, *(pArr + j), *(pArr + j + 1));
				--j;
			}
		}
	}
	
	void reinsort(double* pArrBeg, double* pArrEnd, double* pCurElem)
	{
		// To print out in-betweens 
		static double* pFirst = pArrBeg;
		Utils::PrintArr<double>(pFirst, pArrEnd);
		
		// Base case
		if (pCurElem == pArrEnd)
		{
			return;
		}
		
		merge(pArrBeg, 0, (pCurElem - pArrBeg - 1), (pCurElem - pArrBeg));
		
		// Recursive case
		reinsort(pArrBeg, pArrEnd, ++pCurElem);
	}
	
	void merge(double* pArr, int p, int q, int r)
	{
		register size_t i, j;
		size_t n1, n2;
		n1 = q - p + 1;
		n2 = r - q;
		double* pArrLeft = (double*)calloc((n1), sizeof(double));
		std::memset(pArrLeft, 0, n1);
		double* pArrRight = (double*)calloc((n2), sizeof(double));
		std::memset(pArrRight, 0, n2);
		for (i = 0; i < n1; ++i)
		{
			pArrLeft[i] = pArr[i];
		}
		for (j = 0; j < n2; ++j)
		{
			pArrRight[j] = pArr[i + j];
		}
		
		i = 0; j = 0;
		while (i < n1 && j < n2)
		{
			if(*(pArrLeft + i) <= *(pArrRight + j))
			{
				*(pArr + i + j) = *(pArrLeft + i);
				++i;
			}
			else
			{
				*(pArr + i + j) = *(pArrRight + j);
				++j;
			}
		}
		while (i < n1)
		{
			*(pArr + i + j) = *(pArrLeft + i);
			++i;
		}
		while (j < n2)
		{
			*(pArr + i + j) = *(pArrRight + j);
			++j;
		}
		free(pArrRight);
		free(pArrLeft);
	}
	
	void mergesort(double* pArr, int p, int r)
	{
		int q;
		if (p < r)
		{
			q = (p + r) / 2;
			mergesort(pArr, p, q);
			mergesort(pArr, q + 1, r);
			merge(pArr, p, q, r);
		}
	}
	
	void quicksort(double* pBeg, double* pEnd)
	{
		// -- Base case -- //
		if (pEnd - pBeg < 2)
		{
			return;
		}
		else if (pEnd - pBeg == 2)
		{
			if (*pBeg > *(pBeg + 1))
			{
				SWAP(double, *pBeg, *(pBeg + 1));
			}
		}
		
		// -- Recursive case -- //
		size_t i, last, size;
		size = pEnd - pBeg;
		size_t pivIndex = size / 2;
		
		std::printf("pivot = %d\n", pivIndex);
		
		// Pick a pivot
		SWAP(double, *pBeg, *(pBeg + pivIndex));
		
		// Break up the array into two sub-arrays:
		// with elements less than the pivot
		// and elements larger than it
		for (i = 1, last = 0; i < size; ++i)
		{
			if (*pBeg > *(pBeg + i))
			{
				++last;
				SWAP(double, *(pBeg + last), *(pBeg + i));
				Printing::PrintArr(pBeg, pEnd);
				std::printf("last = %d\n", last);
			}
		}
		SWAP(double, *pBeg, *(pBeg + last));
		
		// Recursively sort the two sub-arrays
		quicksort(pBeg, pBeg + last);
		quicksort(pBeg + last + 1, pEnd);
	}
} // Sorting 


namespace Searching
{
	// Binary search
	int binsrc(double* pArrBeg, double* pArrEnd, double val)
	{
		static double* pFirst = pArrBeg;
		int mid = (pArrEnd - pArrBeg) / 2;
		
		if ((pArrEnd - pArrBeg) == 1 && 
					*pArrBeg != val && *pArrEnd != val)
		{
			return -1;
		}
		
		if (*(pArrBeg + mid) == val)
		{
			return (pArrBeg + mid) - pFirst;
		}
		else if (val > *(pArrBeg + mid))
		{
			return binsrc((pArrBeg + mid), pArrEnd, val);
		}
		else
		{
			return binsrc(pArrBeg, (pArrEnd - mid), val);
		}
	}
	
	int binmerge(double* pArrBeg, double* pArrEnd, double* pElem)
	{
		static double* pFirst = pArrBeg;
		int mid = (pArrEnd - pArrBeg) / 2;
		
		if (*(pArrBeg + mid) == *pElem)
		{
			return (pArrBeg + mid) - pFirst;
		}
		else if (mid == 0 && *pElem > *(pArrBeg + mid))
		{
			return pArrBeg + 1 - pFirst;
		}
		else if (mid == 0 && *pElem < *(pArrBeg + mid))
		{
			return pArrBeg - pFirst;
		}
		else if (*pElem > *(pArrBeg + mid))
		{
			return binmerge((pArrBeg + mid), pArrEnd, pElem);
		}
		else
		{
			return binmerge(pArrBeg, (pArrEnd - mid), pElem);
		}
	}
	
} // Searching 