// inversion.cpp 

#include <cstdlib>
#include <cstdio>

#define MAX 255

#include "d:\\projects\\algorithms\\sorting.h"

typedef unsigned long long UINT64;
typedef unsigned int UINT32;

void merge(UINT64*, UINT64*);
void mergesort(UINT64*, UINT64*);
void readFile(char*, UINT64**, UINT32*);


int main(int argc, char** argv)
{
	UINT64* pArr = NULL;
	UINT32 size;
	
	if (argc == 2)
	{
		readFile(argv[1], &pArr, &size);
		std::fprintf(stdout, "size = %u\n", size);
		std::fprintf(stdout, "first = %llu\n", *pArr);
		
		if (pArr != NULL)
		{
			delete[] pArr;
		}
	}
	
	UINT64 arr[] = {7, 5, 3, 1, 2, 6, 4, 43, 29, 10, 10};
	mergesort(arr, arr + sizeof(arr) / sizeof(UINT64));
	Utils::PrintArr(arr, arr + sizeof(arr) / sizeof(UINT64));
	
	return 1;
}

void readFile(char* filename, UINT64** ppArrOut, UINT32* pSize)
{
	FILE* fp = NULL;
	char c;
	char buf[MAX];
	char* pBuf = buf;
	unsigned int u32size;
	UINT64 u64cur;
	UINT64* pArrNums = NULL;
	size_t i;
	
	fp = std::fopen(filename, "r");
	if (fp != NULL)
	{
		// get the size of the array
		std::fscanf(fp, "%u\n", &u32size);
		
		pArrNums = new UINT64[u32size];
		// fill up the array
		while (std::fscanf(fp, "%llu", &u64cur) == 1)
		{
			*pArrNums++ = u64cur;
			// std::fprintf(stdout, "%llu\n", u64cur);
			//break;
		}
		//std::fprintf(stdout, "size = %u\n", u32size);
		std::fclose(fp);
	}
	// pass the values out 
	*pSize = u32size;
	*ppArrOut = (pArrNums - u32size);
}

void merge(UINT64* pBeg, UINT64* pEnd)
{
	size_t i = 0, j = 0;
	size_t size = pEnd - pBeg;
	size_t n1 = size / 2;
	size_t n2 = size - n1;
		
	UINT64* lArr = new UINT64[n1];
	UINT64* rArr = new UINT64[n2];
	
	while ((pBeg  + i + j) != pEnd)
	{
		if (i < n1)
		{
			*(lArr + i) = *(pBeg + i);
			++i;
		}
		else
		{
			*(rArr + j) = *(pBeg + i + j);
			++j;
		}
	}
	for (i = 0, j = 0; i < n1 && j < n2;)
	{
		if (*(lArr + i) < *(rArr + j))
		{
			*(pBeg + i + j) = *(lArr + i);
			++i;
		}
		else
		{
			*(pBeg + i + j) = *(rArr + j);
			++j;
		}
	}
	if (i < n1) 
	{
		while (i < n1)
		{
			*(pBeg + i + j) = *(lArr + i);
			++i;
		}
	}
	else
	{
		while (j < n2)
		{
			*(pBeg + i + j) = *(rArr + j);
			++j;
		}
	}
	delete[] lArr;
	delete[] rArr;
}

void mergesort(UINT64* pBeg, UINT64* pEnd)
{
	Utils::PrintArr(pBeg, pEnd);
	size_t size = pEnd - pBeg;
	if (size == 1)
	{
		return;
	}
	else
	{
		mergesort(pBeg, pBeg + size / 2);
		mergesort(pBeg + size / 2, pEnd);
		merge(pBeg, pEnd);
		Utils::PrintArr(pBeg, pEnd);
	}
}