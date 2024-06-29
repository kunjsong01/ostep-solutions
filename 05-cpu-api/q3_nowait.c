#include <unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main() {
    int pid = fork();

    if(pid < 0) {
        fprintf(stderr, "fork failed");
    }
    else if(pid == 0) {
        printf("child process = %d\n", (int) getpid());
    }
    else {
        wait(NULL);
        printf("parent process = %d\n", (int) getpid());
    }

    return 0;
}