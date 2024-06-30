#include <stdio.h>
#include <sys/time.h> // for gettimeofday()
#include <unistd.h> // for sleep()

int main() {
    struct timeval begin;
    struct timeval end;

    gettimeofday(&begin, NULL);
    sleep(1); //
    //sleep(1);
    // sleep(1);
    gettimeofday(&end, NULL);

    printf("Time diff: seconds=%ld, useconds=%d\n",
        end.tv_sec - begin.tv_sec,
        end.tv_usec - begin.tv_usec);

    return 0;
}