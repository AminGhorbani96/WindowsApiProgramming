
#include <stdio.h>
#include <Windows.h>

void printLog(const char* ProcessName, const char* Message)
{
	printf_s("[Log of Process : %s] : %s \n", ProcessName, Message);
}

void CreatingSemaphore(LPCWSTR objectName)
{
	HANDLE hSemaphore = NULL;
	DWORD SlastError = 0;

	hSemaphore = CreateSemaphore(NULL, 1, 1, objectName);

	if (hSemaphore == NULL)
	{
		SlastError = GetLastError();
		printLog("ProcessB", "Error While Creating Semaphore");
		printf("Error Code %d \n\n", SlastError);
	}
	else
	{
		printLog("ProcessB", "Semaphore Created Successfuly");
	}

}

void CreatingMutexWithSecurityAttrib(LPCWSTR objectName)
{

	DWORD SMlastError = 0;
	SECURITY_ATTRIBUTES sa;
	sa.bInheritHandle = true;

	HANDLE hMutex_s;
	hMutex_s = CreateMutex(&sa, FALSE, objectName);


	if (hMutex_s == NULL)
	{
		SMlastError = GetLastError();

		printLog("ProcessB", "Error While Creating Mutex with security attrib");
		printf("Error code :  %d \n\n", SMlastError);
	}
	else
	{
		printLog("ProcessB", "Mutex with sa created Successfuly");
	}

}


void CreatingMutex(LPCWSTR objectName)
{


	HANDLE hMutex;
	hMutex = CreateMutex(NULL, FALSE, objectName);
	DWORD lError = 0;

	if (hMutex == NULL)
	{
		lError = GetLastError();
		
		printLog("ProcessB", "Error While Creating Mutex");
		printf("Error code :  %d \n\n", lError);
	}
	else
	{
		printLog("ProcessB", "Mutex without sa created Successfuly");
		printf("Mutex Handle is : %d\n\n", hMutex);
	}

}

void OpeningExistMutex(LPCWSTR objectName)
{
	HANDLE oMutex;
	DWORD oError;
	oMutex = OpenMutex(SYNCHRONIZE, FALSE, objectName);

	if (oMutex == NULL)
	{
		oError = GetLastError();

		printLog("ProcessB", "Error While Opening Mutex");
		printf("Error code :  %d \n\n", oError);
	}
	else
	{
		printLog("ProcessB", "Mutex Opened Successfuly");
		printf("Mutex Handle is : %d\n\n", oMutex);

	}

}


int main()
{
	HANDLE hMutex = NULL;
	DWORD lastError = 0;
	BOOL CHandle = false;

	printLog("ProcessB", "Create Semaphore With 'AminObject' Name ...");

	CreatingSemaphore(TEXT("AminObject"));

	printLog("ProcessB", "Create Mutex with &sa and 'AminObject' Name ...");
	CreatingMutexWithSecurityAttrib(TEXT("AminObject"));

//	printLog("ProcessB", "Create Mutex : ");
	//CreatingMutex(TEXT("AminObject"));

	printLog("ProcessB", "Open Mutex : ");
	OpeningExistMutex(TEXT("AminObject"));


	getchar();

	return 0;



}