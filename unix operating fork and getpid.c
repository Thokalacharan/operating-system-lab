#include<stdio.h>     // Include standard I/O functions (printf)
#include<unistd.h>    // Include Unix system calls (fork, getpid)
#include<stdlib.h>    // Include standard library for exit() function

 int main() {
    int pid, pid1, pid2;

    // Create a new process by calling fork
    pid = fork();

    // Check if fork() was successful (pid = -1 indicates an error)
    if (pid == -1) {
        // If fork failed, print an error message and exit the program
        printf("Error in process creation\n");
        exit(1);  // Exit the program with a non-zero exit code
    }

    // If pid != 0, it means we're in the parent process
    if (pid != 0) {
        // Get the process ID of the parent process using getpid()
        pid1 = getpid();
        // Print the parent process ID
        printf("\nThe parent ID is %d\n", pid1);
    }
    // If pid == 0, it means we're in the child process
    else {
        // Get the process ID of the child process using getpid()
        pid2 = getpid();
        // Print the child process ID
        printf("\nThe child process ID is %d\n", pid2);
    }
}
