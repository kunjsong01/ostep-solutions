* **Measure sys call overheads**  

back-to-back *gettimeofday()*: 

from <sys/time.h>

[code](timeOfDay.c)

result: 
```
~/ostep/ostep-solutions/06-limited-direct-execution$ ./timeOfDay 
Time diff: seconds=1, useconds=3350
```

More *sleep(1)* statements, more *useconds* overheads.

[code](sys_call_overhead.c)

*open()* comes from <fcntl.h>

*exit()* comes from <stdlib.h>

result:
```
~/ostep/ostep-solutions/06-limited-direct-execution$ ./sys_call_overhead 
read system call overhead sec diff = 0; usec diff = 0
read system call overhead sec diff = 0; usec diff = 0
read system call overhead sec diff = 0; usec diff = 0
read system call overhead sec diff = 0; usec diff = 0
read system call overhead sec diff = 0; usec diff = 0
```

system call overhead < 1 uS on macOS

* **Measure context switch overhead**

Need to find equivalent calls to *sched_setscheduler* on macOS
https://stackoverflow.com/questions/45227009/alternative-to-shed-getaffinity-cpu-set-t-etc

