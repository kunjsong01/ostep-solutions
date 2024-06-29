#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// cpu-api homework code Q1

int
main(int argc, char *argv[])
{
    printf("hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    int x = 100;
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        x = x - 1; // child's own copy of x
        printf("hello, I am child (pid:%d), x=%d\n", (int) getpid(), x);
    } else {
        x = x + 1; // parent's own copy of x
        // parent goes down this path (original process)
        printf("hello, I am parent of %d (pid:%d), x=%d\n",
	       rc, (int) getpid(), x);
    }
    return 0;
}