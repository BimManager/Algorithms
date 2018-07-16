// crack.c 

//#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

int scmp(char*, char*);

int main(int argc, char** argv)
{
	size_t i;
	char szBuffer[BUFSIZ];
	memset(szBuffer, '\0', sizeof(szBuffer));
	
	const char* pszSalt = "XX";
	const char* pszPassword = NULL;
	char* pszResult = NULL;
	int iOk;
	
	if (argc != 2)
	{
		puts("Usage: ./crack k");
		return 1;
	}
	
	// Read the user's password and encrypt it 
	pszPassword = crypt(argv[1], pszSalt);
	
	const char* const cpcszPass = (const char* const)pszPassword;
	
	puts(pszPassword);
	
	puts("\nPlease enter the password");
	
	fgets(szBuffer, BUFSIZ, stdin);
	
	// To discard the last char '\n'
	szBuffer[strlen(szBuffer) - 1] = '\0';
	
	pszResult = crypt(szBuffer, cpcszPass);
	
	puts(pszResult);
	puts(cpcszPass);
	//iOk = strcmp(pszResult, pszPassword);
	iOk = memcmp(pszResult, cpcszPass, strlen(pszResult) - 1);
	printf("iOk = %d\n", iOk);
	
	iOk = strcmp(pszResult, cpcszPass);
	printf("iOk = %d\n", iOk);
	
	//iOk = scmp(pszResult, cpcszPass);
	printf("iOk = %d\n", iOk);
	
	
	puts(iOk ? "Access granted." : "Access denied.");
	
	return iOk ? 0 : 1;
}

int scmp(char* pszStrA, char* pszStrB)
{
	while (*pszStrA)
	{
		printf("lhs = %c; rhs = %c\n", *pszStrA, *pszStrB);
		if (*pszStrA != *pszStrB)
			return *pszStrA - *pszStrB;
		
		++pszStrA;
		++pszStrB;
	}
	return 0;
}