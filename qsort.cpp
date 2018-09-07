// qsort.cpp 
// Fun with Quick sort

#include <cstdlib>
#include <cstdio>
#include <io.h>

#include <ctime>
#include <fstream>

#include "D:\\Projects\\Algorithms\\Sorting.h"

/*#define SWAP(t, x, y) { t z = x; \
						  x = y; \
						  y = z; }*/
				
template<class T>				
struct IComparer
{
	virtual int operator()(T*, T*) = 0;
};

struct IntComparer : public IComparer<int>
{
	virtual int operator()(int* pIntA, int* pIntB)
	{
		if (*pIntA > *pIntB)
		{
			return 1;
		}
		else if (*pIntA < *pIntB)
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
};

template<class T>
int pick_pivot(T* pBeg, T* pEnd, IComparer<T>*);
template<class T>
void qsort(T* pBeg, T* pEnd, IComparer<T>*);
template<class T>
void qsort3(T*, T*, IComparer<T>*);
template<class T>
void partition(T*, T*, IComparer<T>*, size_t*, size_t*);

int main(void)
{
	try
	{
		clock_t t1, t2;
		double dur;
		IntComparer cmpr;
		char* filename;
		size_t arrSize;
		FILE* fp;
		
		///int arrInts[] = { 4, 4, 3, 5, 1, 3, 4, 5, 1, 4, 3, 5, 1, 1 };
		//size_t size = sizeof(arrInts) / sizeof(int);
		
		if (argc != 2)
		{
			return;
		}
		
		filename = argv[1];
		
		// open a file
		fp = fopen(filename, "r");
		
		// read the file
		fscanf(fp, "%d", 
		
		t1 = std::clock();
		
		qsort(arrInts, arrInts + size, &cmpr);
		//qsort3(arrInts, arrInts + size, &cmpr);
		
		t2 = std::clock();
		
		dur = 1000 * (t2 - t1) / CLOCKS_PER_SEC;
		
		Utils::PrintArr(arrInts, arrInts + size);
		std::printf("time: %.10fms\n", dur);
		
	}
	catch(...)
	{
		
	}
}

template<class T>
int pick_pivot(T* pBeg, T* pEnd, IComparer<T>* pCmp)
{
	return rand() % (pEnd - pBeg);
}


template<class T>
void qsort(T* pBeg, T* pEnd, IComparer<T>* pCmp)
{
	// Base case
	if (pBeg == pEnd)
	{
		return;
	}
	
	// Recursive case
	size_t i, last, p, size = pEnd - pBeg;
	
	// Select a pivot
	//p = size / 2;
	//SWAP(T, *pBeg, *(pBeg + p));
	
	// Break down the array into two/three subarrays
	for (i = 1, last = 0; i < size; ++i)
	{
		if ((*pCmp)(pBeg, pBeg + i) == 1)
		{
			++last;
			SWAP(T, *(pBeg + i), *(pBeg + last));
		}
	}
	SWAP(T, *pBeg, *(pBeg + last));
	
	// Recursively sort the subarrays
	qsort(pBeg, pBeg + last, pCmp);
	qsort(pBeg + last + 1, pEnd, pCmp);
}

template<class T>
void qsort3(T* pBeg, T* pEnd, IComparer<T>* pCmp)
{
	// Base case
	if (pBeg == pEnd)
	{
		return;
	}
	
	Utils::PrintArr(pBeg, pEnd);
	
	// Recursive case 
	size_t st, end, p;
	
	// Pick out the pivot
	p = *pBeg;
	
	// Partition the array into three subarrays
	partition(pBeg, pEnd, pCmp, &st, &end);
	
	// Recursively call the function
	qsort3(pBeg, pBeg + st, pCmp);
	qsort3(pBeg + end, pEnd, pCmp);
}

template<class T>
void partition(T* pBeg, T* pEnd, IComparer<T>* pCmp, size_t* pSubBeg, size_t* pSunEnd)
{
	size_t i, lt, gt;
	
	for (i = 1, lt = 0, gt = pEnd - pBeg - 1; i <= gt;)
	{
		if ((*pCmp)(pBeg + lt, pBeg + i) == 1)
		{
			SWAP(T, *(pBeg + lt), *(pBeg + i));
			++lt;
			++i;
		}
		else if ((*pCmp)(pBeg + lt, pBeg + i) == -1)
		{
			SWAP(T, *(pBeg + i), *(pBeg + gt));
			--gt;
		}
		else
		{
			++i;
		}
	}
	*pSubBeg = lt;
	*pSunEnd = ++gt;
}