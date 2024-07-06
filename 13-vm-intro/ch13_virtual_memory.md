* **Q1-2**

free - get amount of free and used memory
-k, -m, or -g displays in different units. 

Not sure what's the counterpart on macOS.

result
```
~/OSTEP$ free -m
               total        used        free      shared  buff/cache   available
Mem:           31937        8818       14085         136        9033       22527
Swap:           1951           0        1951
``` 

* **Q3-4**

[code](memory_use.c)

stdlib.h : malloc, free

Run the following cmd in one terminal to watch regularly updates of free
```
watch -d free
```

Then run the program in another window: 
```
./memory_use 50 10
```

Observed changes in used, free and available columns in the "Mem:" row.
No changes in other columns or rows

Try {33%, 50%, 100%, 200%} of the available RAM: 
```
~/OSTEP$ ./memory_use 10922 10
not enough memory
~/OSTEP$ ./memory_use 16384 10
~/OSTEP$ ./memory_use 32768 10
~/OSTEP$ ./memory_use 65536 10
```
Observation:
For 200%: shared column in Mem row changed 

* **Q5-6**
pmap - process memory map

-x extended
-d device
-A range
-XX

ps auxw

"The pmap output reports the process' memory usage, including all the components it uses, such as libraries and binary files. The columns include the memory address, offset, permission, and name." 
source: https://www.redhat.com/sysadmin/pmap-command

result: 
```
~/OSTEP$ pmap -x 22702
22702:   ./memory_use 10 60
Address           Kbytes     RSS   Dirty Mode  Mapping
00005d02e1119000       4       4       0 r---- memory_use
00005d02e111a000       4       4       0 r-x-- memory_use
00005d02e111b000       4       4       0 r---- memory_use
00005d02e111c000       4       4       4 r---- memory_use
00005d02e111d000       4       4       4 rw--- memory_use
00005d02e24a5000     132       4       4 rw---   [ anon ]
00007239271ff000   10244   10244   10244 rw---   [ anon ]
0000723927c00000     160     160       0 r---- libc.so.6
0000723927c28000    1620    1100       0 r-x-- libc.so.6
0000723927dbd000     352     124       0 r---- libc.so.6
0000723927e15000       4       0       0 ----- libc.so.6
0000723927e16000      16      16      16 r---- libc.so.6
0000723927e1a000       8       8       8 rw--- libc.so.6
0000723927e1c000      52      20      20 rw---   [ anon ]
0000723927e66000      12       8       8 rw---   [ anon ]
0000723927e7d000       8       4       4 rw---   [ anon ]
0000723927e7f000       8       8       0 r---- ld-linux-x86-64.so.2
0000723927e81000     168     168       0 r-x-- ld-linux-x86-64.so.2
0000723927eab000      44      44       0 r---- ld-linux-x86-64.so.2
0000723927eb7000       8       8       8 r---- ld-linux-x86-64.so.2
0000723927eb9000       8       8       8 rw--- ld-linux-x86-64.so.2
00007ffc75cf9000     132      16      16 rw---   [ stack ]
00007ffc75dee000      16       0       0 r----   [ anon ]
00007ffc75df2000       8       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- ------- 
total kB           13024   11964   10344

```

where 22702 is the pid of the memory_use.c program

result:
```
22872:   ./memory_use 65536 60
Address           Kbytes     RSS   Dirty Mode  Mapping
000055fbb5dda000       4       4       0 r---- memory_use
000055fbb5ddb000       4       4       0 r-x-- memory_use
000055fbb5ddc000       4       4       0 r---- memory_use
000055fbb5ddd000       4       4       4 r---- memory_use
000055fbb5dde000       4       4       4 rw--- memory_use
000055fbb7865000     132       4       4 rw---   [ anon ]
000073c1ca800000     160     160       0 r---- libc.so.6
000073c1ca828000    1620    1100       0 r-x-- libc.so.6
000073c1ca9bd000     352     124       0 r---- libc.so.6
000073c1caa15000       4       0       0 ----- libc.so.6
000073c1caa16000      16      16      16 r---- libc.so.6
000073c1caa1a000       8       8       8 rw--- libc.so.6
000073c1caa1c000      52      20      20 rw---   [ anon ]
000073c1cab3d000      12       8       8 rw---   [ anon ]
000073c1cab54000       8       4       4 rw---   [ anon ]
000073c1cab56000       8       8       0 r---- ld-linux-x86-64.so.2
000073c1cab58000     168     168       0 r-x-- ld-linux-x86-64.so.2
000073c1cab82000      44      44       0 r---- ld-linux-x86-64.so.2
000073c1cab8e000       8       8       8 r---- ld-linux-x86-64.so.2
000073c1cab90000       8       8       8 rw--- ld-linux-x86-64.so.2
00007ffd44f12000     132      12      12 rw---   [ stack ]
00007ffd44f58000      16       0       0 r----   [ anon ]
00007ffd44f5c000       8       4       0 r-x--   [ anon ]
ffffffffff600000       4       0       0 --x--   [ anon ]
---------------- ------- ------- ------- 
total kB            2780    1716      96
```

* **More processes' pmap**

android studio - 14.75G
result
```
0000000000200000      4K r---- java
0000000000201000      4K r-x-- java
0000000000202000      4K r---- java
0000000000203000      4K rw--- java
000000000146e000   6572K rw---   [ anon ]
0000000740000000 2378752K rw---   [ anon ]
00000007d1300000 766976K -----   [ anon ]
0000000800000000  61276K rw---   [ anon ]
0000000803bd7000 987300K -----   [ anon ]
0000759014000000  20540K rw---   [ anon ]
000075901540f000  44996K -----   [ anon ]
000075901a900000     16K -----   [ anon ]
000075901a904000   1008K rw---   [ anon ]
...
...
...
00007592c90ba000      8K r---- ld-linux-x86-64.so.2
00007592c90bc000    168K r-x-- ld-linux-x86-64.so.2
00007592c90e6000     44K r---- ld-linux-x86-64.so.2
00007592c90f1000      4K r--s- platform-objectSerializer-annotations.jar
00007592c90f2000      8K r---- ld-linux-x86-64.so.2
00007592c90f4000      8K rw--- ld-linux-x86-64.so.2
00007ffe33172000    136K rw---   [ stack ]
00007ffe331f1000     16K r----   [ anon ]
00007ffe331f5000      8K r-x--   [ anon ]
ffffffffff600000      4K --x--   [ anon ]
 total         15468456K

```

firefox - 3.94G, same ending address, so all addresses here are virtual!
result
```
00000000406b4000      8K r-xs- .glXXXXXX (deleted)
0000000040e60000    688K rw---   [ anon ]
0000000041551000    688K rw---   [ anon ]
0000032da0e00000   1024K rw---   [ anon ]
00000468b3600000   1024K rw---   [ anon ]
00000732f9900000   1024K rw---   [ anon ]
000007e768b00000   1024K rw---   [ anon ]
00000a6cf6800000   1024K rw---   [ anon ]
...
...
...
0000776481e88000      8K r---- ld-linux-x86-64.so.2
0000776481e8a000      8K rw--- ld-linux-x86-64.so.2
00007ffee1b96000    136K rw---   [ stack ]
00007ffee1bb8000      8K rw---   [ anon ]
00007ffee1bcc000     16K r----   [ anon ]
00007ffee1bd0000      8K r-x--   [ anon ]
ffffffffff600000      4K --x--   [ anon ]
 total          4135392K
```

