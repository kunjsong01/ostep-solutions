* **Q1**  
[code](q1.c)

result
```
~/ostep/ostep-solutions/05-cpu-api$ ./q1
hello world (pid:2519)
hello, I am parent of 2520 (pid:2519), x=101
hello, I am child (pid:2520), x=99
```
Each process has their own copy of x. It's two x's in two different address spaces. 

* **Q2**  
[code](q2.c)

result
```
~/ostep/ostep-solutions/05-cpu-api$ ./q2
parent of 2611 (pid:2610) writing
child (pid:2611) writing
~/ostep/ostep-solutions/05-cpu-api$ cat test.txt
parent
child
```
Both processes can write to the fd. 

* **Q3** 
[code](q3.c)

 