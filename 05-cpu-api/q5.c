#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if(pid < 0) {
        fprintf(stderr, "fork failed");
    }
    else if(pid == 0) {
        pid_t result = wait(NULL);
        printf("child process pid=%d, wait() returns: %d\n", (int) getpid(), (int) result);
    }
    else {
        printf("parent process pid=%d\n", (int) getpid());
    }
}