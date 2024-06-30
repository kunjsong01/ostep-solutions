#include <unistd.h> // for read()
#include <fcntl.h> // for open()
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h> // for exit()

int main() {
    struct timeval begin, end;
    char buf[256]; // read buffer

    int fd = open("test.txt", O_RDONLY);

    if (fd == -1) {
        printf("open failed\n");
        exit(1);
    }

    gettimeofday(&begin, NULL);

    // 5x repeated zero byte read system calls
    read(fd, buf, 0);
    read(fd, buf, 0);
    read(fd, buf, 0);
    read(fd, buf, 0);
    read(fd, buf, 0);

    gettimeofday(&end, NULL);

    printf("read system call overhead in usec = %lf\n",
    (double) (((end.tv_sec * 1000000 + end.tv_usec) - (begin.tv_sec * 1000000 - begin.tv_usec)) / 5));

    close(fd);

    return 0;
}