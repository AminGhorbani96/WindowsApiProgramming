

#include <Windows.h>
#include <stdio.h>
int main(int arg, char* argv)
{

	HANDLE hfile = INVALID_HANDLE_VALUE;
	BOOL writefilestatus = FALSE;
	char buffer[1024] = {NULL};
	hfile = CreateFile(TEXT("\\\\.\\mailslot\\serverslot"), GENERIC_ALL, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

	if (hfile == INVALID_HANDLE_VALUE)
	{
		printf("%s : %d\n", "Failed To creatFile Error Number is ", GetLastError());
		return -1;
	}
	scanf_s("%s", buffer, 1024);
	writefilestatus = WriteFile(hfile, (LPCVOID)buffer, sizeof(buffer), NULL, NULL);

	if (writefilestatus == FALSE)
	{
		printf("%s : %d\n", "Failed To WriteFile Error Number is ", GetLastError());
		return -1;
	}

	CloseHandle(hfile);

	return 0;

}