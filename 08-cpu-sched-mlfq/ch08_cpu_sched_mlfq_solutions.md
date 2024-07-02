* **Q1**

Allotment for each queue: 
  Time spent by each job before demoted by the scheduler. 
Quantum:
  Time slice. Jobs in each queue is scheduled by RR, hence we need to specify a quantum. 

result
```
~/ostep/ostep-homework-forked/cpu-sched-mlfq$ ./mlfq.py -n 2 -j 2 -l  0,20,0:5,30,0 -s 100 -c
Final statistics:
  Job  0: startTime   0 - response   0 - turnaround  30
  Job  1: startTime   5 - response   5 - turnaround  45

  Avg  1: startTime n/a - response 2.50 - turnaround 37.50
```

* **Q2**
Skipped. 
Commands to replicate the examples in this chapter. 

* **Q3**
Using -n 1 to just specify one queue. Now everything is RR. 

* **Q4**
./mlfq.py -S -n 2 -i 1 -l 0,100,0:20,100,9 -a 10 -q 10 -c

MLFQ with 2 levels, allotment 10, jobs stay at the same queue when issuing I/O. Job 2 games the scheduler by issuing an I/O every 9 instructions. 

* **Q5**
10 / (5%) = 200
So -B 190 would do. 

* **Q6**
Skipped.
Run some experiment to see the effect of -I. 