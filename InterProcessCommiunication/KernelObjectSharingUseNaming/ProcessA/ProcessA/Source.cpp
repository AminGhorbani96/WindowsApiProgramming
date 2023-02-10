
#include <stdio.h>
#include <Windows.h>


void printLog(const char* ProcessName, const char* Message)
{
	printf_s("[Log of Process : %s] : %s \n", ProcessName, Message);
}


int main()
{
	HANDLE hMutex = NULL;
	DWORD lastError = 0;
	BOOL CHandle = false;


	printLog("ProcessA", "LOG :: Creating Mutex With Name 'AminObject'");


	hMutex = CreateMutex(NULL, FALSE, TEXT("AminObject"));

	if (hMutex == NULL)
	{
		lastError = GetLastError();

		printLog("ProcessA", "Error While Creating Mutex");
		printf("Error Code %s \n\n", lastError);
		return -1;
	}

	printLog("ProcessA", "Mutext with name AminObject Created Successfully");

	printf("Mutex Handle : %d", hMutex);
	

	
	getchar();

	CHandle =  CloseHandle(hMutex);

	if (CHandle == false)
	{
		lastError = GetLastError();
		printLog("ProcessA", "Error While Closing Mutex Handle.");
		printf("Error Code %s \n\n", lastError);

		return -1;
	}

	printLog("ProcessA", "Mutex Handle Closed Successfully ");

	return 0;

}