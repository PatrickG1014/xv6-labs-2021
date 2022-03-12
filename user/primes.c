#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int p[2];

  pipe(p);
  if (fork() == 0) {
    close(p[1]);
    int prime;
    int fd = p[0];
    while (read(fd, (char *)&prime, 4) > 0) {
      printf("prime %d\n", prime);
      int n;
      pipe(p);
      while (read(fd, (char *)&n, 4) > 0) {
        if (n % prime != 0) {
          write(p[1], (char *)&n, 4);
        }
      }
      close(p[1]);
      if (fork() > 0) {
        close(fd);
        close(p[0]);
        wait(0);
        exit(0);
      }
      fd = p[0];
    }
    close(fd);
    exit(0);
  } else { // the first process
    close(p[0]);
    for (int i = 2; i <= 35; ++i) { // feed the numbers 2 through 35 into the pipeline
      write(p[1], (char *)&i, 4);
    }
    close(p[1]);
  }

  wait(0);
  exit(0);
}
