// simpleSorting.h
// The following algorithms are implemented:
// selection sort, insertion sort, bubble sort

#ifndef SIMPLE_SORTING_H
#define SIMPLE_SORTING_H
#define SWAP(t, x, y) { t z = x; \
								  x = y; \
								  y = z; }

namespace SimpleSorting
{
	enum Order { ASCENDING, DESCENDING };
	
	template<class T>
	struct IComparer 
	{
		int operator()(T, T) = 0; // a pure virtual method
		private:
		enum Order order;
	};
	
	// Selection sort
	template<class T>
	void selsort(T* pBeg, T* pEnd, IComparer<T>* pCmpr)
	{
		size_t i, j, size = pEnd - pBeg;
		
		for (i = 0; i < size - 1; ++i)
		{
			size_t min = i;
			
			for (j = i + 1; j < size; ++j)
			{
				if (pCmpr(*(pBeg + min), *(pBeg + j)) == 1)
				{
					min = j;
				}
			}
			SWAP(T, *(pBeg + i), *(pBeg + min));
		}
	}
} // SimpleSorting
#endif // SIMPLE_SORTING_H