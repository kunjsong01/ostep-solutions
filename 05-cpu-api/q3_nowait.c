#include <unistd.h>
#include<sys/wait.h>
#include<stdio.h>

int main() {
    int pid = vfork();
    int x = 100;

    if(pid < 0) {
        fprintf(stderr, "fork failed");
    }
    else if(pid == 0) {
        x++;
        printf("child process = %d, x=%d\n", (int) getpid(), x);
    }
    else {
        x++;
        printf("parent process = %d, x=%d\n", (int) getpid(), x);
    }

    return 0;
}