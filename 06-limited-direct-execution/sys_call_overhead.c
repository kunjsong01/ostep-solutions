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



    for(int i = 0; i < 5; i++) {
        gettimeofday(&begin, NULL);
        read(fd, buf, 0);
        gettimeofday(&end, NULL);
        printf("read system call overhead sec diff = %ld; usec diff = %d\n",
        (end.tv_sec - begin.tv_sec), (end.tv_usec - end.tv_usec));
    }

    close(fd);

    return 0;
}