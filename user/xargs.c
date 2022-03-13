#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/param.h"
#include "user/user.h"

#define MAXBUF 64

int
main(int argc, char *argv[])
{
  char buf[MAXBUF];
  int new_argc = argc - 1;
  char *new_argv[MAXARG];
  int p = 0;
  int space_flag = 0;

  for (int i = 1; i < argc; ++i)
    new_argv[i - 1] = argv[i];

  while (read(0, &buf[p], sizeof(char))) {
    if (buf[p] != ' ' && buf[p] != '\n') {
      ++p;
      continue;
    }
    if (buf[p] == ' ') {
      if (p == 0)
        continue;
      space_flag = 1;
    } else {
      space_flag = 0;
    }
    buf[p] = '\0';
    if (strlen(buf) > 0) {
      new_argv[new_argc] = (char *)malloc((p + 1) * sizeof(char));
      strcpy(new_argv[new_argc++], buf);
    }
    p = 0;
    if (space_flag)
      continue;
    // the char read in is '\n'
    new_argv[new_argc] = 0;
    if (fork() == 0) {
      exec(new_argv[0], new_argv);
      fprintf(2, "exec %s failed\n", new_argv[0]);
      exit(1);
    }
    wait(0);
    new_argc = argc - 1;
  }

  exit(0);
}
