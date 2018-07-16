// crack.c 

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset, memcmp
#include <wchar.h>
#include <math.h>

// For the DES-based algorithm
// the total length of a hash password
// will be 13 characters; 2 for the salt
// followed by 11 more and a null-terminating char 
#define HASHLEN 14
// The length of a password 5 characters at most
#define PASSLEN 6
#define SALTLEN 3

/* --- Function Prototypes --- */
void CrackDES(char*, char**);
char GetChar(int);
void UnitTest();

/* --- Main --- */
int main(int argc, char** argv)
{
	size_t i;
	char szBuffer[HASHLEN];
	char* pszHash;
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
	
	pszHash = crypt("efds", "XX");
	
	printf("hash = %s;\n", pszHash);
	
	CrackDES(pszHash, &pszPassword);
	
	printf("\nPASSWORD: %s\n", pszPassword);
	//UnitTest();
	
	return 0;
}

/* --- Function Definitions --- */
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
	size_t i, j;
	char szSalt[SALTLEN];
	char szPassGuess[PASSLEN];
	char szHash[HASHLEN];
	char* pszHashGuess = NULL;
	char* pszPass = calloc(PASSLEN, sizeof(char));
	
	// Initiliase a few arrays
	memset(szPassGuess, '\0', PASSLEN);
	
	// Copy the salt from the hash
	strncpy(szSalt, pszHash, 2);
	printf("Salt = %s\n" , szSalt);
	strcpy(szHash, pszHash);
	
	for (i = 0; i < pow(52, 5); ++i)
	{
		pszHashGuess = crypt(szPassGuess, szSalt);
		// printf("guess = %s; hash = %s\n" , pszHashGuess, szHash);
		
		if (strcmp(szHash, pszHashGuess, HASHLEN) == 0)
		{
			break;
		}
		else
		{
			if (i / 52 == 0)
			{
				szPassGuess[0] = GetChar(i);
				printf("%s\n" , szPassGuess);
			}
			else if (i / (52 * 52) == 0)
			{
				szPassGuess[0] = GetChar(i / 52);
				szPassGuess[1] = GetChar(i % 52);
				printf("%s\n" , szPassGuess);
			}
			else if (i / (52 * 52 * 52) == 0)
			{
				szPassGuess[0] = GetChar(i / 52 / 52);
				szPassGuess[1] = GetChar(i / 52);
				szPassGuess[2] = GetChar(i % 52);
				printf("%s\n" , szPassGuess);
			}
			else if (i / (52 * 52 * 52 * 52) == 0)
			{
				szPassGuess[0] = GetChar(i / 52 / 52 / 52);
				szPassGuess[1] = GetChar(i / 52 / 52);
				szPassGuess[2] = GetChar(i / 52);
				szPassGuess[3] = GetChar(i % 52);
				printf("%s\n" , szPassGuess);
			}
			else
			{	
				szPassGuess[0] = GetChar(i / 52 / 52 / 52 / 52);
				szPassGuess[1] = GetChar(i / 52 / 52 / 52);
				szPassGuess[2] = GetChar(i / 52 / 52);
				szPassGuess[3] = GetChar(i / 52);
				szPassGuess[4] = GetChar(i % 52);
				printf("%s\n" , szPassGuess);
			}
		}
	}
	
	// If the password cracked, then copy it 
	// into pszPass
	strcpy(pszPass, szPassGuess);
	*ppPassOut = pszPass;
}
