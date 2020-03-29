// sorting.h
// Sorting algorithms

#ifndef SORTING_ALG_H
#define SORTING_ALG_H

#include <cstring>

#include <iostream>

#define SWAP(t, a, b) { t c = a; \
					      a = b; \
						  b = c; }

namespace Sorting 
{
	enum SortingOrder { ASCENDING, DESCENDING };
	template<class T>
	struct IComparer
	{
		virtual int operator()(T*, T*) = 0;
		SortingOrder order;
	};
	
	struct KeyValuePair
	{
		int key;
		int value;
	};
	
	// Selection sort
	template<class T>
	void SelSort(T* pBeg, T* pEnd, IComparer<T>* pCmpr)
	{
		size_t i, j, size = pEnd - pBeg;
		
		for (i = 0; i < size - 1; ++i)
		{
			size_t min = i;
			
			for (j = i + 1; j < size; ++j)
			{
				if ((*pCmpr)(pBeg + min, pBeg + j) == 1 &&
					pCmpr->order == SortingOrder::ASCENDING)
				{
					min = j;
				}
				else if ((*pCmpr)(pBeg + min, pBeg + j) == -1 &&
					pCmpr->order == SortingOrder::DESCENDING)
				{
					min = j;
				}
			}
			SWAP(T, *(pBeg + i), *(pBeg + min));
		}
	}
	
	// Insertion sort
	template<class T>
	void InSort(T* pBeg, T* pEnd, IComparer<T>* pCmpr)
	{
		size_t i, j, size = pEnd - pBeg;
		for (i = 0; i < size - 1; ++i)
		{
			j = i + 1;
			if (pCmpr->order == SortingOrder::ASCENDING)
			{
				while (j > 0 && (*pCmpr)(pBeg + j - 1, pBeg + j) == 1)
				{
					SWAP(T, *(pBeg + j - 1), *(pBeg + j));
					--j;
				}
			}
			else
			{
				while (j > 0 && (*pCmpr)(pBeg + j - 1, pBeg + j) == -1)
				{
					SWAP(T, *(pBeg + j - 1), *(pBeg + j));
					--j;
				}
			}
		}
	}
	
	// Bubble sort
	template<class T>
	void BubbleSort(T* pBeg, T* pEnd, IComparer<T>* pCmpr)
	{
		size_t i, j, swap, size = pEnd - pBeg;
		
		do
		{
			swap = 0;
			for (i = 0; i < size - 1; ++i)
			{
				j = i + 1;
				
				if ((*pCmpr)(pBeg + i, pBeg + j) == 1 && 
					pCmpr->order == SortingOrder::ASCENDING)
					{
						SWAP(T, *(pBeg + i), *(pBeg + j));
						++swap;
					}
				else if ((*pCmpr)(pBeg + i, pBeg + j) == -1 &&
					pCmpr->order == SortingOrder::DESCENDING)
					{
						SWAP(T, *(pBeg + i), *(pBeg + j));
						++swap;
					}
			}
		} while (swap != 0);
	}
	
	// Counting sort
	void CountSort(int* pBeg, int* pEnd)
	{
		size_t i, size = pEnd - pBeg;
		int min = *pBeg;
		int max = *pBeg;
		int dif;
		int index;
		
		// Dig up (track down) 
		// the maximum and minimum values
		for (i = 1; i < size; ++i)
		{
			if (*(pBeg + i) > max)
			{
				max = *(pBeg + i);
			}
			else if (*(pBeg + i) < min)
			{
				min = *(pBeg + i);
			}
		}
		dif = max - min + 1;
		
		std::cout << "(min, max, dif) = (" 
				  << min << ", "
				  << max << ", "
				  << dif << ") "
				  << '\n';
		
		int* pArr = new int[dif];
		
		// Zero the array
		for (i = 0; i < dif; ++i)
		{
			*(pArr + i) = 0;
		}
		
		// Fill up the array
		for (i = 0; i < size; ++i)
		{
			index = *(pBeg + i) - min;
			++*(pArr + index);
		}
		
		// Sort out the original array
		for (i = 0; i < dif; ++i)
		{
			while (*(pArr + i) > 0)
			{
				*pBeg++ = (i + min);
				--*(pArr + i);
			}
		}
		
		delete[] pArr;
	}
	
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
	void Qsort(T* pBeg, T* pEnd)
	{
		// Base case
		if (pEnd - pBeg < 2)
		{
			return;
		}
		else if (pEnd - pBeg == 2)
		{
			if (*pBeg > *(pBeg + 1))
			{
				SWAP(T, *pBeg, *(pBeg + 1));
			}
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
	
	template<typename T, class V>    
	void UniQsort(T* pBeg, T* pEnd, IComparer<V>* pCmp)
	{
		// Base case
		if (pEnd - pBeg < 2)
		{
			return;
		}
		else if (pEnd - pBeg == 2)
		{
			if ((*pCmp)(pBeg, pBeg + 1) == 1)
			{
				SWAP(T, *pBeg, *(pBeg + 1));
			}
			return;
		}
		
		// Recursive case
		size_t i, last, size;
		// 1. Pick a pivot
		size = pEnd - pBeg;
		SWAP(T, *pBeg, *(pBeg + size / 2));
		
		// 2. Split the array into two sub-arrays
		for (last = 0, i = 1; i < size; ++i)
		{
			if ((*pCmp)(pBeg, pBeg + i) == 1)
			{
				++last;
				SWAP(T, *(pBeg + i), *(pBeg + last));
			}
		}
		SWAP(T, *pBeg, *(pBeg + last));
		
		// 3. Recursively sort the two sub-arrays
		UniQsort(pBeg, pBeg + last, pCmp);
		UniQsort(pBeg + last + 1, pEnd, pCmp);
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