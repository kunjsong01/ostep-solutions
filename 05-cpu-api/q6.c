#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main() {
    int pid = fork();

    if(pid < 0) {
        fprintf(stderr, "fork failed");
    }
    else if(pid == 0) {
        sleep(1);
        printf("child process pid=%d\n", (int) getpid());
    }
    else {
        //int result = waitpid(pid, NULL, WEXITSTATUS(pid)); // wrong!
        int result = waitpid(pid, NULL, 0);
        printf("parent process pid=%d, waitpid() returned %d\n", (int) getpid(), result);
    }
}