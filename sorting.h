// sorting.h
// Sorting algorithms

#ifndef SORTING_ALG_H
#define SORTING_ALG_H
#include <iostream>
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