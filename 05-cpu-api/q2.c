#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int
main(int argc, char *argv[])
{
    int fd = open("./test.txt", O_CREAT|O_WRONLY, S_IRWXU);
    if (fd == -1) {
        fprintf(stderr, "open failed\n");
        exit(1);
    }
    //char buf[] = "hello";
    //write(fd, "hello", strlen(buf));

    int rc = fork();
    if (rc < 0) {
        // fork failed; exit
        fprintf(stderr, "fork failed\n");
        exit(1);
    } else if (rc == 0) {
        // child (new process)
        char buf[] = "child\n";
        printf("child (pid:%d) writing\n", (int) getpid());
        write(fd, buf, strlen(buf));
    } else {
        // parent goes down this path (original process)
        char buf[] = "parent\n";
        printf("parent of %d (pid:%d) writing\n",
	       rc, (int) getpid());
        write(fd, buf, strlen(buf));
    }

    return 0;
}
