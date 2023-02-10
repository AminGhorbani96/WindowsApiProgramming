#include <windows.h>
#include <stdio.h>

void GetCurrentProcessSessionId()
{
	DWORD processID = GetCurrentProcessId();
	DWORD sessionID;
	if (ProcessIdToSessionId(processID, &sessionID)) {
		printf(
			"Process '%u' runs in Terminal Services session '%u'\n",
			processID, sessionID);
	}
	else {
		// ProcessIdToSessionId might fail if you don't have enough rights
		// to access the process for which you pass the ID as parameter.
		// Notice that it is not the case here because we're using our own process ID.
		printf(
			"Unable to get Terminal Services session ID for process '%u'\n",
			processID);
	}

}

void CreateGloabalEvent()
{

	HANDLE hEvent;
	hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("Global\\TestingGlobalEvent"));

	if (hEvent == NULL)
	{
		printf("Unable to Create Global Event");
	}
	else
	{
		printf("Global Event Created Successfuly \n");
	}
}


void CreateLocalEvent()
{

	HANDLE hEvent;
	hEvent = CreateEvent(NULL, FALSE, FALSE, TEXT("Local\\TestingLocalEvent"));

	if (hEvent == NULL)
	{
		printf("Unable to Create Local Event");
	}
	else
	{
		printf("Local Event Created Successfuly \n");
	}
}

int main()
{
	GetCurrentProcessSessionId();

	CreateGloabalEvent();

	CreateLocalEvent();

	getchar();

	return 0;
	
}