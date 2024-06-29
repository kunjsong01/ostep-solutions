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

[code with wait()](q3.c)

[code with vfork()](q3_nowait.c)

wait() : sys/wait.h

fork() : unitstd.h

with wait() result
```
~/ostep/ostep-solutions/05-cpu-api$ ./q3_nowait 
child process = 7289
parent process = 7286
``` 

with vfork() result on macOS Sonoma 14.5:
```
~/ostep/ostep-solutions/05-cpu-api$ ./q3_nowait
parent process = 8866, x=101
child process = 8867, x=101
```

Compliation warning on macOS Sonoma 14.5 with Apple clang version 15.0.0 (clang-1500.3.9.4): 
```
~/ostep/ostep-solutions/05-cpu-api$ make q3_nowait
gcc -o q3_nowait q3_nowait.c -Wall
q3_nowait.c:6:15: warning: 'vfork' is deprecated: Use posix_spawn or fork [-Wdeprecated-declarations]
    int pid = vfork();
              ^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/unistd.h:604:1: note: 'vfork' has been explicitly marked deprecated here
__deprecated_msg("Use posix_spawn or fork")
^
/Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/usr/include/sys/cdefs.h:218:48: note: expanded from macro '__deprecated_msg'
        #define __deprecated_msg(_msg) __attribute__((__deprecated__(_msg)))
                                                      ^
1 warning generated.
```

with vfork() result on Ubuntu 22.04 with gcc 11.4.0: 
```
~/OSTEP$ ./a.out 
child process = 6557, x=101
parent process = 6556, x=101
```

no compilation error on Ubuntu. 

* **Q4** 

[code](q4.c)

**exec()** replaces the current process with a new process image. The statement below will be ignored. 

**execve(cmd, arg, NULL);** doesn't execute the cmd on macOS.

The exec family functions - some searches the PATH for an execuable file (e.g. execvp and execv), and some don't. 

* **Q5** 

On macOS: 
pid_t == __darwin_pid_t == __int32_t == int

so pid_t is essentially a signed 32 bit integer.

result
```
~/ostep/ostep-solutions/05-cpu-api$ ./q5
parent process pid=18027
child process pid=18028, wait() returns: -1
```

**wait()** returns -1 in child process. Negative returns from system call *usually* means some kind of failed call. 



