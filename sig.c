#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

static void sighandler(int signo) {

  if(signo == SIGUSR1) {
    printf("    The parent process of the current signal is %d\n", getppid());
  }else if(signo == SIGINT) {
    umask(0000);
    printf("    Exiting due to the signal %d\n", signo);
    int a = open("file.txt", O_RDWR | O_APPEND, 0666);
    write(a, "Exited due to SIGINT\n", sizeof("Exited due to SIGINT\n"));
    close(a);
    exit(0);
  }
}

int main() {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("The pid of the current signal is %d\n", getpid());
    sleep(1);
  }
  return 1;
}
