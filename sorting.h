// sorting.h
// Sorting algorithms

#ifndef SORTING_ALG_H
#define SORTING_ALG_H


namespace Sorting 
{
	// Insertion sort
	void insort(double*, size_t);
	
	// Merge sort
	void merge(double*, int, int, int);
	void mergesort(double*, int, int);
} // Sorting

namespace Searching
{
	// Binary search
	int binsrc(double*, double*, double);
} // Searchig
#endif // SORTING_ALG_H