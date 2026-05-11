// CS3331
// Zack and Jacob
// Summer 2026
// This program demonstrates the use of fork() to create a process tree. 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    printf("Parent PID = %d\n", getpid());
    for (int i = 0; i < 2; i++) {
        int pid = fork(); // Create a child process
        if (pid == 0) { // This block is executed by the child process
            fork();
            wait(NULL);
            printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            exit(0); // Terminate the child process
        } else { // This block is executed by the parent process
            printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
            wait(NULL); // Wait for the child process to finish
        }
    }
    exit(0); // Terminate the parent process
}