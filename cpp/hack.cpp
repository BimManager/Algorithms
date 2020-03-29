// hack.cpp
// meddling with processes
#pragma comment(lib, "kernel32")
#pragma comment(lib, "user32")
#pragma comment(lib, "gdi32")

#ifndef UNICODE
#define UNICODE
#endif

#ifndef _UNICODE
#define _UNICODE
#endif

#include <windows.h>
#include <strsafe.h>
#include <tchar.h>
#include <stdio.h>	
#include <strsafe.h>
#include <stdlib.h>
#include <iostream>

#define BUFFER 128

extern "C" const IMAGE_DOS_HEADER __ImageBase;

void DumpModule();
HANDLE GetProcess(LPCTSTR=0, LPCTSTR=0);
void PrintEnvironmentVariable(PCTSTR);
void CreateNewProcess();

int _tmain(int argc, PTCHAR* argv, PTCHAR* env) {
	
	SetConsoleOutputCP(866);
	//LPTSTR lpWinTitle = TEXT("Calculator");
	LPTSTR lpClassName = TEXT("CalcFrame");
	HANDLE hProcess;
	_tprintf(TEXT("argc = %d\n"),argc);
	if(argc == 2) {
		//LPTSTR pszCmdLineArgs = GetCommandLine();
		//_tprintf(TEXT("pszCmdLineArgs = %s\n"),pszCmdLineArgs); 
		hProcess = GetProcess(argv[1]);
	}
	if(argc == 3) {
		LPTSTR pszCmdLineArgs = GetCommandLine();
		_tprintf(TEXT("pszCmdLineArgs = %s\n"),pszCmdLineArgs); 
		
		TCHAR szTitle[BUFFER];
		SecureZeroMemory(szTitle, BUFFER * sizeof(TCHAR));
		if(S_OK == StringCchCopy(
				szTitle, 
				_countof(szTitle),
				argv[1])) {
					_tprintf(TEXT("Text: %s\n"), szTitle);
						PTCHAR pszTitle = szTitle;
						pszTitle += _tcslen(argv[1]);
						*pszTitle++ = TEXT(' ');
						if(S_OK == StringCchCopy(
									pszTitle,
									_countof(szTitle),
									argv[2])) {												
												WriteConsole(
													GetStdHandle(STD_OUTPUT_HANDLE),
													szTitle, 
													20,
													NULL,
													0
												);	
												hProcess = GetProcess(szTitle);	
											}
						
						
					}	
	}
	else
		hProcess = GetProcess(0, lpClassName);
	
	CloseHandle(hProcess);
	//DumpModule();
	
	// print out the process' environment variables
	/*_tprintf(TEXT("Environment variables:"));
	while(*env){
		_tprintf(TEXT("\n%s"), *env++);
	}*/					
	
	
	//PrintEnvironmentVariable(TEXT("INCLUDE"));
	//PrintEnvironmentVariable(TEXT("USERPROFILE"));
	
	
	PTSTR pszCurDir = (LPTSTR)HeapAlloc(
					GetProcessHeap(),
					HEAP_ZERO_MEMORY,
					MAX_PATH * sizeof(TCHAR)
				);
	
	if(pszCurDir){
		DWORD dwResult = GetCurrentDirectory(
					MAX_PATH,
					pszCurDir
					);
		if(dwResult)
			_tprintf(TEXT("\npszCurDir = %s"), pszCurDir);
		
		HeapFree(GetProcessHeap(), 0, pszCurDir);
	}
	
	CreateNewProcess();

	
	return 0;
}

HANDLE GetProcess(LPCTSTR lpWinTitle, 
								LPCTSTR lpClassName) {
	HWND hwnd = FindWindow(lpClassName, lpWinTitle);
	if(hwnd) {
		PTSTR pszTitle = 
			(LPTSTR) HeapAlloc(
				GetProcessHeap(),
				0,
				BUFFER * sizeof(TCHAR)
			);
		if(pszTitle) {
			_tprintf(TEXT("Memory allocated.\n"));
			if(GetWindowText(hwnd, pszTitle, BUFFER)) {
				_tprintf(TEXT("Title: %s.\n"),pszTitle);
				WriteConsole(
					GetStdHandle(STD_OUTPUT_HANDLE),
					pszTitle, 
					_tcslen(pszTitle),
					NULL,
					0
				);		
			}
			else
				_tprintf(TEXT("ERROR: %ld\n"), GetLastError());
			
			if(HeapFree(GetProcessHeap(),0, pszTitle))
				_tprintf(TEXT("\nMemory released.\n"));
			else
				_tprintf(TEXT("ERROR: %ld\n"), GetLastError());
		}
		_tprintf(TEXT("hwnd = %p\n"),hwnd);
		DWORD dwProcessId; 
		GetWindowThreadProcessId(hwnd, &dwProcessId);
		if(dwProcessId) {
			_tprintf(TEXT("Process ID = %x\n"),dwProcessId);
			HANDLE hProcess = OpenProcess(
								PROCESS_ALL_ACCESS,
								FALSE,
								dwProcessId
							);
			if(hProcess) {
				_tprintf(TEXT("hProcess = %p\n"),hProcess);
				return hProcess;
			}
			else {
				_tprintf(TEXT("ERROR: %ld\n"), GetLastError());
				return NULL;
			}
		}
		else {
			_tprintf(TEXT("ERROR: %ld\n"), GetLastError());
			return NULL;
		}
	}
	else {
		_tprintf(TEXT("ERROR: %ld\n"), GetLastError());
		return NULL;
	}		
}

void DumpModule() {
	// Get the base address of the running application
	// Can be different from the running module if this code is in a DLL
	HMODULE hModule = GetModuleHandle(NULL);
	_tprintf(TEXT("with GetModuleHandle(NULL) = %p\n"), hModule);
	
	// Use the pseudo-variable __ImageBase to get
	// the base address of the current hModule/hInstance
	_tprintf(TEXT("with __ImageBase = %p\n"),(HMODULE)&__ImageBase);
	
	// Pass the address of the current method DumpModule
	// as a parameter to GetModuleHandleEx to get the 
	// address of the current module hModule/hInstance
	hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		(PCTSTR)DumpModule,
		&hModule);
	_tprintf(TEXT("with GetModuleHandleEx = %p\n"), hModule);
}

void PrintEnvironmentVariable(PCTSTR pszVariableName) {
	
	PTSTR pszValue = NULL;
	// get the size of the buffer required
	DWORD dwResult = GetEnvironmentVariable(
						pszVariableName,
						pszValue,
						0 // to get the number of characters wanted along with 
						  // the null character
					);
	_tprintf(TEXT("\nCharacters needed: %d"), dwResult);
	
	if(dwResult) {
		pszValue = (PTSTR)HeapAlloc(
					GetProcessHeap(),
					0,
					dwResult * sizeof(TCHAR)
					);
		if(pszValue) {
			_tprintf(TEXT("\nMemory Allocated successfully"));
			
			dwResult = GetEnvironmentVariable(
				pszVariableName,
				pszValue,
				dwResult);
			
			if(dwResult) {
				_tprintf(TEXT("\n%s = %s"), pszVariableName, pszValue);
			}
			
			HeapFree(GetProcessHeap(), 0, pszValue);
		}
		else
			std::cerr<<"\nERROR: "<<GetLastError();
	}
	else
			std::cerr<<"\nERROR: "<<GetLastError();
}

void CreateNewProcess() {
	// Prepare a STARTUPINFO structure for spawning processes
	STARTUPINFO si = { sizeof(si) };
	SECURITY_ATTRIBUTES saProcess, saThread;
	PROCESS_INFORMATION piProcessB, piProcessC;
	TCHAR szPath[MAX_PATH];
	
	saProcess.nLength = sizeof(saProcess);
	saProcess.lpSecurityDescriptor = NULL;
	saProcess.bInheritHandle = FALSE;
	
	saThread.nLength = sizeof(saProcess);
	saThread.lpSecurityDescriptor = NULL;
	saThread.bInheritHandle = FALSE;
	
	// Spawn Process B
	_tcscpy_s(szPath, _countof(szPath), TEXT("Notepad"));
	CreateProcess(NULL, szPath, &saProcess, &saThread,
		FALSE, 0, NULL, NULL, &si, &piProcessB);
		
	_tprintf(TEXT("\nhProcessA = %p"), GetModuleHandle(NULL));
	_tprintf(TEXT("\nhProcessB = %p"), piProcessB.hProcess);
	_tprintf(TEXT("\nhThreadB = %p"), piProcessB.hThread);
}