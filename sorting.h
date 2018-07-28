// sorting.h
// Sorting algorithms

#ifndef SORTING_ALG_H
#define SORTING_ALG_H

#include <iostream>


#define SWAP(t, a, b) { t c = a; \
													a = b; \
													b = c; \
											}

namespace Sorting 
{
	// Insertion sort
	void insort(double*, size_t);
	
	// Recursive insertion sort
	void reinsort(double*, double*, double*);
	
	// Merge sort
	void merge(double*, int, int, int);
	void mergesort(double*, int, int);
	
	// Quick sort
	void quicksort(double*, double*);
	
	template<typename T>
	void Qsort(T*pBeg, T* pEnd)
	{
		// Base case
		if (pEnd - pBeg < 2)
		{
			return;
		}
		else if (pEnd - pBeg == 2 && *pBeg > *(pBeg + 1))
		{
			SWAP(T, *pBeg, *(pBeg + 1));
			return;
		}
		
		// Recursive case
		size_t i, last, size;
		// 1. Pick out a pivot
		size = pEnd - pBeg;
		SWAP(T, *pBeg, *(pBeg + size / 2));
		// 2. Split up the array into two sub-arrays
		for (last = 0, i = 1; i < size; ++i)
		{
			if (*pBeg > *(pBeg + i))
			{
				++last;
				SWAP(T, *(pBeg + i), *(pBeg + last));
			}
		}
		SWAP(T, *pBeg, *(pBeg + last));
		// 3. Recursive sort the two sub-arrays
		Qsort(pBeg, pBeg + last);
		Qsort(pBeg + last + 1, pEnd);
	}
} // Sorting

namespace Searching
{
	// Binary search
	int binsrc(double*, double*, double);
	int binmerge(double*, double*, double*);
} // Searchig

namespace Utils
{
	// Print array
	template<typename T>
	void PrintArr(T* pBeg, T* pEnd)
	{
		while (pBeg != pEnd)
		{
			std::cout << *pBeg++ << "; ";
		}
		std::cout<<'\n';
	}
}
#endif // SORTING_ALG_H