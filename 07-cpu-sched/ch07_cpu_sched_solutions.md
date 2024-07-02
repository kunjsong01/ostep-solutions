* **Q1**

Same {turnaround, response, wait} time as all three jobs have the same running time. 

result: 
```
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p FIFO -j 3 -l 200,200,200 -c 
ARG policy FIFO
ARG jlist 200,200,200

Here is the job list, with the run time of each job: 
  Job 0 ( length = 200.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 200.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 200.00 secs ( DONE at 200.00 )
  [ time 200 ] Run job 1 for 200.00 secs ( DONE at 400.00 )
  [ time 400 ] Run job 2 for 200.00 secs ( DONE at 600.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 200.00  Wait 0.00
  Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
  Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

  Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p SJF -j 3 -l 200,200,200 -c 
ARG policy SJF
ARG jlist 200,200,200

Here is the job list, with the run time of each job: 
  Job 0 ( length = 200.0 )
  Job 1 ( length = 200.0 )
  Job 2 ( length = 200.0 )


** Solutions **

Execution trace:
  [ time   0 ] Run job 0 for 200.00 secs ( DONE at 200.00 )
  [ time 200 ] Run job 1 for 200.00 secs ( DONE at 400.00 )
  [ time 400 ] Run job 2 for 200.00 secs ( DONE at 600.00 )

Final statistics:
  Job   0 -- Response: 0.00  Turnaround 200.00  Wait 0.00
  Job   1 -- Response: 200.00  Turnaround 400.00  Wait 200.00
  Job   2 -- Response: 400.00  Turnaround 600.00  Wait 400.00

  Average -- Response: 200.00  Turnaround 400.00  Wait 200.00
```

* **Q2**

Same {turnaround, response, wait} time as the running time of three jobs are in ascending order.

command used: 
```
./scheduler.py -p FIFO -j 3 -l 100,200,300 -c
./scheduler.py -p SJF -j 3 -l 100,200,300 -c
```

* **Q3**

RR has better response time but worse {turnaround, wait} time. 
SJF has better turnaround time but worse {response, wait} time. 

RR result:
```
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p RR -j 3 -l 100,200,300 -q 1 -c
...
Final statistics:
  Job   0 -- Response: 0.00  Turnaround 298.00  Wait 198.00
  Job   1 -- Response: 1.00  Turnaround 499.00  Wait 299.00
  Job   2 -- Response: 2.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 1.00  Turnaround 465.67  Wait 265.67


```

SJF result: 
```
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p SJF -j 3 -l 100,200,300 -c
...
Final statistics:
  Job   0 -- Response: 0.00  Turnaround 100.00  Wait 0.00
  Job   1 -- Response: 100.00  Turnaround 300.00  Wait 100.00
  Job   2 -- Response: 300.00  Turnaround 600.00  Wait 300.00

  Average -- Response: 133.33  Turnaround 333.33  Wait 133.33

```

* **Q4**

All jobs have the same running time, arriving at the same time. SJF and FIFO deliver the same turnaround time. 

* **Q5**

All jobs have the same running time equivalent to the time slice of RR. SJF and RR deliver the same response time. 

* **Q6**

SJF response time increases as the job length increases. 

result: 
```
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p SJF -j 3 -l 10,20,30 -c 
...
  Average -- Response: 13.33  Turnaround 33.33  Wait 13.33
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p SJF -j 3 -l 15,25,35 -c
...
  Average -- Response: 18.33  Turnaround 43.33  Wait 18.33
~/OSTEP/ostep-homework/cpu-sched$ ./scheduler.py -p SJF -j 3 -l 20,30,40 -c 
...
  Average -- Response: 23.33  Turnaround 53.33  Wait 23.33
```

* **Q7**

RR response time increases as the quantum length increases. 

cmd line
```
./scheduler.py -p RR -j 3 -l 100,200,300 -c -q {1,2,3,4,5}
```

Given N jobs, the worst-case response time = (N-1) * quantum, assuming all jobs arrive at the same time. 
This is the start time of the N-th job. 