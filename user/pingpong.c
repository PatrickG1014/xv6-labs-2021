#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p1[2];
  int p2[2];
  int pid;
  char byte;

  pipe(p1);
  pipe(p2);
  if (fork() == 0) {
    pid = getpid();
    close(p1[1]);
    close(p2[0]);
    read(p1[0], &byte, 1);
    printf("%d: received ping\n", pid);
    close(p1[0]);
    write(p2[1], "C", 1);
    close(p2[1]);
    exit(0);
  } else {
    pid = getpid();
    close(p1[0]);
    close(p2[1]);
    write(p1[1], "P", 1);
    close(p1[1]);
    read(p2[0], &byte, 1);
    printf("%d: received pong\n", pid);
    close(p2[0]);
  }
  wait(0);
  exit(0);
}
