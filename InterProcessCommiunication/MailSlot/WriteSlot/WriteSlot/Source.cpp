

#include <Windows.h>
#include <stdio.h>
int main(int arg, char* argv)
{

	int memsize = 1024;
	char mbuffer[1024] = { NULL };

	printf("MailSlot Server running ....\n ");

	HANDLE hmailslot = INVALID_HANDLE_VALUE;
	BOOL reafilestatus = FALSE;
	HANDLE hrecievefile = INVALID_HANDLE_VALUE;
	BOOL writereceivedata = FALSE;



	hmailslot = CreateMailslot(TEXT("\\\\.\\mailslot\\serverslot"), 0, MAILSLOT_WAIT_FOREVER, NULL);

	if (hmailslot == INVALID_HANDLE_VALUE)
	{
		printf("%s : %d\n", "Failed To Createmailslot Error Number is ", GetLastError());
		return -1;
	}
	
	reafilestatus = ReadFile(hmailslot, mbuffer, memsize, NULL, NULL);

	if (reafilestatus == FALSE)
	{
		printf("%s : %d\n", "Failed To Readfile Error Number is ", GetLastError());
		return -1;
	}

	printf("Data is : %s \n", mbuffer);

	hrecievefile = CreateFile(TEXT("c:\\users\\public\\data.txt"), GENERIC_ALL, 0, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hrecievefile == INVALID_HANDLE_VALUE)
	{
		printf("%s : %d\n", "Couldnt Write Data to file Error Number is ", GetLastError());
		return -1;
	}
	writereceivedata = WriteFile(hrecievefile, mbuffer, sizeof(mbuffer), NULL, NULL);
	if (writereceivedata == FALSE)
	{
		printf("%s : %d\n", "Failed To WriteFile Error Number is ", GetLastError());
		return -1;
	}

	CloseHandle(hmailslot);
	CloseHandle(hrecievefile);

	return 0;


}