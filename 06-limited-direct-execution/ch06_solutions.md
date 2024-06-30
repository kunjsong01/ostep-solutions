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
read system call overhead in usec = 74302.000000
~/ostep/ostep-solutions/06-limited-direct-execution$ ./sys_call_overhead 
read system call overhead in usec = 28407.000000
~/ostep/ostep-solutions/06-limited-direct-execution$ ./sys_call_overhead 
read system call overhead in usec = 319378.000000
~/ostep/ostep-solutions/06-limited-direct-execution$ ./sys_call_overhead 
read system call overhead in usec = 195589.000000
~/ostep/ostep-solutions/06-limited-direct-execution$ ./sys_call_overhead 
read system call overhead in usec = 79363.000000
```

average = 139407.8 microseconds
