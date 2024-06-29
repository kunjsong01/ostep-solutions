#include <stdio.h>
#include <stdlib.h> // for exit()
#include <unistd.h>

int main()
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int pid = fork();
    int x = 100;
    if (pid < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (pid == 0) {
        // child (new process)
        close(STDOUT_FILENO);
        printf("hello, I am child (pid:%d), x=%d\n", (int) getpid(), x);
    } else {
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d), x=%d\n",
	       pid, (int) getpid(), x);
    }
    return 0;
}
