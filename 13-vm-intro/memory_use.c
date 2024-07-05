#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	if(argc != 3) {
		printf("wrong args\n");
		exit(1);
	}

	printf("PID=%d\n", (int)getpid());

	// 1 << 10 is kilobytes, 1 << 20 is megabytes, or just (x * 1024 * 1024)
	int requested = atoi(argv[1]) * (1 << 20);
	size_t mSize = requested / sizeof(int);
	int* arr = (int*) malloc(requested);
	if(!arr) {
		printf("not enough memory\n");
		exit(1);
	}

	struct timeval begin, current;
	gettimeofday(&begin, NULL);
	int duration = atoi(argv[2]); // total run time

	while(1) {
		gettimeofday(&current, NULL);
		if(current.tv_sec - begin.tv_sec >= duration) {
			break;
		}
		for(int i = 0; i < mSize; i++) {
			*(arr + i) = 0;
		}
	}

	free(arr);
	return 0;
}

