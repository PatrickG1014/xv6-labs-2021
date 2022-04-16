# Lab: file system

[Lab fs: File system](https://pdos.csail.mit.edu/6.828/2021/labs/fs.html)

- [ ] Large files (*moderate*)
- [x] Symbolic links (*moderate*)
- [ ] Optional challenge exercises

## Exercises

- Large files
  
  Modify `bmap()` so that it implements a doubly-indirect block, in addition to direct blocks and a singly-indirect block. You'll have to have only 11 direct blocks, rather than 12, to make room for your new doubly-indirect block; you're not allowed to change the size of an on-disk inode. The first 11 elements of `ip->addrs[]` should be direct blocks; the 12th should be a singly-indirect block (just like the current one); the 13th should be your new doubly-indirect block. You are done with this exercise when `bigfile` writes 65803 blocks and `usertests` runs successfully:

  ```shell
  $ bigfile
  ...
  wrote 65803 blocks
  done; ok
  $ usertests
  ...
  ALL TESTS PASSED
  $ 
  ```

- Symbolic links
  
  You will implement the `symlink(char *target, char *path)` system call, which creates a new symbolic link at path that refers to file named by target. For further information, see the man page symlink. To test, add symlinktest to the Makefile and run it. Your solution is complete when the tests produce the following output (including usertests succeeding).

  ```shell
  $ symlinktest
  Start: test symlinks
  test symlinks: ok
  Start: test concurrent symlinks
  test concurrent symlinks: ok
  $ usertests
  ...
  ALL TESTS PASSED
  $ 
  ```

- Optional challenge exercises
  
  Support triple-indirect blocks.

## Grading

```shell
== Test running bigfile ==
$ make qemu-gdb
running bigfile: FAIL (37.3s)
    ...
         $ bigfile
         ..
         wrote 268 blocks
         bigfile: file is too small
         $ qemu-system-riscv64: terminating on signal 15 from pid 2280 (make)
    MISSING '^wrote 65803 blocks$'
    QEMU output saved to xv6.out.bigfile
== Test running symlinktest ==
$ make qemu-gdb
(2.2s)
== Test   symlinktest: symlinks ==
  symlinktest: symlinks: OK
== Test   symlinktest: concurrent symlinks ==
  symlinktest: concurrent symlinks: OK
== Test usertests ==
$ make qemu-gdb
usertests: OK (90.3s)
== Test time ==
time: FAIL
    Cannot read time.txt
Score: 59/100
```
