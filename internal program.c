#include <stdio.h> 
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>  // Include this header for wait()
#include <unistd.h>
#include <dirent.h>

int main() {
    // Create a child process
    
    pid_t pid = fork();

    if (pid < 0) {
        // Fork failed
        printf("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // Child process
        printf("Child process started. PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());

        // Open a directory
        DIR *dir = opendir(".");
        if (dir == NULL) {
            perror("Failed to open directory");
            exit(EXIT_FAILURE);
        }

        printf("Files in the current directory:\n");
        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            printf("  %s\n", entry->d_name);
        }

        closedir(dir);
        printf("Child process exiting.\n");
        exit(EXIT_SUCCESS);
    } else {
        // Parent process
        printf("Parent process. PID: %d\n", getpid());
        wait(NULL); // Wait for child process to finish
        printf("Parent process exiting.\n");
    }

    return 0;
}
