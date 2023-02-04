#include <Windows.h>
#include <stdio.h>
int main()
{
	int shmem_size = 16;

	HANDLE fmhndl = INVALID_HANDLE_VALUE;
	HANDLE mutex = INVALID_HANDLE_VALUE;

	LPVOID lpMapAddress = NULL;
	char* data = NULL;

	mutex = CreateMutex(NULL, FALSE, TEXT("mutex_sample_name"));


	fmhndl = CreateFileMapping(INVALID_HANDLE_VALUE, NULL, PAGE_READWRITE, 0, shmem_size, TEXT("MemoryFileMap"));

	if (mutex == NULL)
	{
		printf("It's Failed to creat MUTEX");
		return -1;
	}
	if (fmhndl == NULL)
	{
		printf("It's Failed to creat FileMapping");
		return -1;
	}

	lpMapAddress = MapViewOfFile(fmhndl, FILE_MAP_READ, 0, 0, shmem_size);

	data = (char*)lpMapAddress;
	
	for (unsigned int c = 0; c < 60; c++)
	{
		WaitForSingleObject(mutex, INFINITE);

		printf("Read shared memory...c=%d\n", data[0]);

		// mutex unlock
		ReleaseMutex(mutex);

		Sleep(1000);
	}

	CloseHandle(fmhndl);
	CloseHandle(mutex);
	return 0;
}