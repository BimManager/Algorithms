// sorting.cpp
// Sorting algorithms

#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "sorting.h"

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
	
} // Searching 