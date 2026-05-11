// CS3331
// Zack and Jacob
// Summer 2026
// This program demonstrates the use of fork() to create a process tree. 
#include <stdio.h>
#include <unistd.h>

void main() {
    int pid = fork(); // Create a child process
    // printf("Process %d: First Split\n", getpid());
    for (int i = 0; i < 3; i++) {
        // printf("Process %d: iteration %d\n", getpid(), i);
        if (fork() == 0) { // This block is executed by the child process
            // printf("Child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
            i++;
        } else if (pid == 0) { // This block is executed by the parent process
            // printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
            break;
        }
    }
}