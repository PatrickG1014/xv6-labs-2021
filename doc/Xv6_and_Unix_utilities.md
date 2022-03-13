# Lab: Xv6 and Unix utilities

[Lab util: Unix utilities](https://pdos.csail.mit.edu/6.828/2021/labs/util.html)

- [x] sleep (easy)
- [x] pingpong (easy)
- [x] primes (moderate)/(hard)
- [x] find (moderate)
- [ ] xargs (moderate)
- [ ] Optional challenge exercises

## Exercises
- sleep
  
  Implement the UNIX program `sleep` for xv6; your `sleep` should pause for a user-specified number of ticks. A tick is a notion of time defined by the xv6 kernel, namely the time between two interrupts from the timer chip. Your solution should be in the file `user/sleep.c`.

- pingpong
  
  Write a program that uses UNIX system calls to ''ping-pong'' a byte between two processes over a pair of pipes, one for each direction. The parent should send a byte to the child; the child should print "<pid>: received ping", where <pid> is its process ID, write the byte on the pipe to the parent, and exit; the parent should read the byte from the child, print "<pid>: received pong", and exit. Your solution should be in the file `user/pingpong.c`.

- primes
  
  Write a concurrent version of prime sieve using pipes. This idea is due to Doug McIlroy, inventor of Unix pipes. The picture halfway down this page and the surrounding text explain how to do it. Your solution should be in the file `user/primes.c`.

- find
  
  Write a simple version of the UNIX find program: find all the files in a directory tree with a specific name. Your solution should be in the file `user/find.c`.

- xargs
  
  Write a simple version of the UNIX xargs program: read lines from the standard input and run a command for each line, supplying the line as arguments to the command. Your solution should be in the file `user/xargs.c`.

- Optional challenge exercises
  
  - Write an uptime program that prints the `uptime` in terms of ticks using the uptime system call. (easy)

  - Support regular expressions in name matching for `find`. `grep.c` has some primitive support for regular expressions. (easy)

  - The xv6 shell (`user/sh.c`) is just another user program and you can improve it. It is a minimal shell and lacks many features found in real shell. For example, modify the shell to not print a $ when processing shell commands from a file (moderate), modify the shell to support wait (easy), modify the shell to support lists of commands, separated by ";" (moderate), modify the shell to support sub-shells by implementing "(" and ")" (moderate), modify the shell to support tab completion (easy), modify the shell to keep a history of passed shell commands (moderate), or anything else you would like your shell to do. (If you are very ambitious, you may have to modify the kernel to support the kernel features you need; xv6 doesn't support much.)

## Grading

```shell
== Test sleep, no arguments ==
$ make qemu-gdb
sleep, no arguments: OK (7.0s)
== Test sleep, returns ==
$ make qemu-gdb
sleep, returns: OK (1.3s)
== Test sleep, makes syscall ==
$ make qemu-gdb
sleep, makes syscall: OK (1.1s)
== Test pingpong ==
$ make qemu-gdb
pingpong: OK (1.0s)
== Test primes ==
$ make qemu-gdb
primes: OK (1.0s)
== Test find, in current directory ==
$ make qemu-gdb
find, in current directory: OK (1.0s)
== Test find, recursive ==
$ make qemu-gdb
find, recursive: OK (1.2s)
== Test xargs ==
$ make qemu-gdb
xargs: FAIL (1.2s)
    Number of appearances of 'hello'
    got:
      0
    expected:
      3
    QEMU output saved to xv6.out.xargs
== Test time ==
time: FAIL
    Cannot read time.txt
Score: 80/100
```