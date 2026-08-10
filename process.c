#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();  // create child process

    if (pid < 0) {
        printf("Process creation failed\n");
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d\n", getpid());
        printf("Child terminating...\n");
        exit(0);
    }
    else {
        // Parent process
        printf("Parent Process: PID = %d\n", getpid());
        printf("Child PID = %d\n", pid);
        wait(NULL);  // wait for child
        printf("Parent terminating...\n");
    }

    return 0;
}