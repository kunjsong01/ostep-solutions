* **Q1**  

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

repeatedly call a simple system call (e.g., performing a 0-byte
read), and time how long it takes
