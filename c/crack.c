// crack.c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset, memcmp
#include <wchar.h>
#include <time.h>
#include <math.h>

// For the DES-based algorithm
// the total length of a hash password
// will be 13 characters; 2 for the salt
// followed by 11 more and a null-terminating char 
#define HASHLEN 14
// The length of a password 5 characters at most
#define PASSLEN 6
#define SALTLEN 3
#define LETTERS 52
#define MAXPASSLEN 5

/* --- Function Prototypes --- */
void CrackDES(char*, char**);
char GetChar(int);
void UnitTest();

/* --- Main --- */
int main(int argc, char** argv)
{
	size_t i;
	clock_t t;
	char szBuffer[HASHLEN];
	char* pszHash = NULL;
	char* pszPassword;
	memset(szBuffer, '\0', sizeof(szBuffer));
	
	// If more or fewer than tho args are provided
	// terminate the execution of the program
	if (argc != 2)
	{
		puts("Usage: ./crack k");
		return 1;
	}
	
	// Copy the content of argv[1] into szBuffer
	strcpy(szBuffer, argv[1]);
	
  //pszHash = crypt("zzzz", "XX");
	//pszHash = crypt(argv[1], "50");
	
	//printf("hash = %s;\n", pszHash);
	
	t = clock();
	CrackDES(argv[1], &pszPassword);
	t = clock() - t;
	
	printf("\nPASSWORD: %s\n", pszPassword);
	printf("Time went by: %.4f\n", ((float)t) / CLOCKS_PER_SEC);
	//UnitTest();
	
	free(pszPassword);
	
	return 0;
}

/* --- Function Definitions --- */
char GetChar(int i)
{
	char chOut;
BEGIN:
	if (i < LETTERS / 2) 
	{
		chOut = 'A' + i;
	}
	else if (i < LETTERS)
	{
		chOut = 'a' + (i - LETTERS / 2);
	}
	else
	{
		i -= LETTERS;
			goto BEGIN;
	}
	return chOut;
}

void UnitTest()
{
	size_t i;
	for (i = 0; i < 78; ++i)
	{
		if (i < 26)
		{
			if (GetChar(i) != 'A' + i)
			{
				puts("Failed\n");
				printf("GetChar = %c; %c; i = %d\n", 
												GetChar(i), 'a' + i, i);
				return;
			}
		}
		else if (i < 52)
		{
			if (GetChar(i) != 'a' + (i - 26))
			{
				puts("Failed\n");
				printf("GetChar = %c; %c; i = %d\n", 
										GetChar(i), 'a' + (i - 26), i);
				return;
			}
		}
		else if(i < 78)
		{
			if (GetChar(i) != 'A' + (i - 52))
			{
				puts("Failed\n");
				printf("GetChar = %c; %c; i = %d\n", 
										GetChar(i), 'a' + (i - 52), i);
				return;
			}
		}
	}
	
	int j;
	for (j = -1; j > -26; --j)
	{
		if (GetChar(j) != 'z' + j + 1)
		{
			puts("Failed\n");
			printf("GetChar = %c; %c; i = %d\n", 
									GetChar(j), 'z' + (j + 1), j);
			return;
		}
	}
	
	puts("Passed\n");
}

void CrackDES(char* pszHash, char** ppPassOut)
{
	register size_t i, j;
	char szSalt[SALTLEN];
	char szPassGuess[PASSLEN];
	char szHash[HASHLEN];
	char* pszHashGuess = NULL;
	char* pszPass = calloc(PASSLEN, sizeof(char));
	
	if (pszPass == NULL)
	{
		fputs("No memory has been allocated. Exiting ... ", stderr);
		return;
	}
	
	// Initiliase a few arrays
	memset(szPassGuess, '\0', PASSLEN);
	
	// Copy the salt from the hash
	strncpy(szSalt, pszHash, 2);
	printf("Salt = %s\n" , szSalt);
	strcpy(szHash, pszHash);
	
	puts("Cracking ... ");
	for (i = 0; i < pow(LETTERS, MAXPASSLEN); ++i)
	{
		pszHashGuess = crypt(szPassGuess, szSalt);
		
		if (strcmp(szHash, pszHashGuess, HASHLEN) == 0)
		{
			break;
		}
		else
		{			
			if (i / LETTERS == 0)
			{
				*szPassGuess = GetChar(i);
			}
			else if (i / (LETTERS * LETTERS) == 0)
			{
				*szPassGuess = GetChar(i / LETTERS);
				*(szPassGuess + 1) = GetChar(i % LETTERS);
			}
			else if (i / (LETTERS * LETTERS * LETTERS) == 0)
			{
				szPassGuess[0] = GetChar(i / LETTERS / LETTERS);
				szPassGuess[1] = GetChar(i / LETTERS);
				szPassGuess[2] = GetChar(i % LETTERS);
			}
			else if (i / (LETTERS * LETTERS * LETTERS * LETTERS) == 0)
			{
				szPassGuess[0] = GetChar(i / LETTERS / LETTERS / LETTERS);
				szPassGuess[1] = GetChar(i / LETTERS / LETTERS);
				szPassGuess[2] = GetChar(i / LETTERS);
				szPassGuess[3] = GetChar(i % LETTERS);
			}
			else
			{	
				szPassGuess[0] = GetChar(i / LETTERS / LETTERS / LETTERS / LETTERS);
				szPassGuess[1] = GetChar(i / LETTERS / LETTERS / LETTERS);
				szPassGuess[2] = GetChar(i / LETTERS / LETTERS);
				szPassGuess[3] = GetChar(i / LETTERS);
				szPassGuess[4] = GetChar(i % LETTERS);
			}
		}
	}
	
	// If the password has been cracked, then copy it 
	// into pszPass
	strcpy(pszPass, szPassGuess);
	*ppPassOut = pszPass;
}


/*
char GetChar(int i)
{
	char chOut;
BEGIN:
	if (i >= 0 && i < 26) 
	{
		chOut = 'A' + i;
	}
	else if (i >= 26 && i < 52)
	{
		chOut = 'a' + (i - 26);
	}
	else
	{
		if (i > 0)
		{
			i -= 52;
			goto BEGIN;
		}
		else
		{
			i += 52;
			goto BEGIN;
		}
	}
	return chOut;
}*/