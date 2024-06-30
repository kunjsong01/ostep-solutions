
all: timeOfDay sys_call_overhead

clean:
	rm -f timeOfDay sys_call_overhead

timeOfDay: timeOfDay.c
	gcc -o timeOfDay timeOfDay.c -Wall

sys_call_overhead: sys_call_overhead.c
	gcc -o sys_call_overhead sys_call_overhead.c -Wall