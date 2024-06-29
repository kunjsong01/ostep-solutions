#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h>

void failOnExit() {
    fprintf(stderr, "sys call failed");
    exit(1);
}

int main()
{
    int fd[2];
    if(pipe(fd) < 0) failOnExit();

    // fd[1] is write, fd[0] is read
    int pid = fork();

    if (pid < 0) {
        failOnExit();
    } else if (pid == 0) {
        // this is the first child
        printf("hello, I am child1 (pid:%d)\n", (int) getpid());
        // fork another one
        int _pid = fork();
        if(_pid < 0) {
            failOnExit();
        } else if(_pid == 0) {
            char buffer[256];
            // this is the second child
            close(fd[1]);
            // set stdin to the write end on the pipe
            dup2(fd[0], STDIN_FILENO);
            int tmp = read(STDIN_FILENO, buffer, 256);
            printf("hello, I am child2 (pid:%d), read returned: %d, tmp=%s\n", (int) getpid(), tmp, buffer);
        } else {
            // this is also the first child
            close(fd[0]); // close the read end on the pipe
            // set stdout to the write end on the pipe
            dup2(fd[1], STDOUT_FILENO);
            // write something and send it to child2
            printf("hi from child1=%d", (int) getpid());
        }
    }

    return 0;
}
