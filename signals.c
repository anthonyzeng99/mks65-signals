#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>


static void sighandler(int signo) {
  if (signo == SIGINT) {
    int file = open("errmessage", O_WRONLY | O_APPEND | O_CREAT, 0644);
    write(file, "Caught SIGINT\n", 15);
    close(file);
    exit(SIGINT);
    } else if(signo == SIGUSR1) {
    printf("Parent Proccess PID:%d\n", getppid());
  }
} 

void print_pid() {
  while(1) {
    printf("Proccess PID:%d\n", getpid());
    sleep(1);
  }
}

 int main () {
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  print_pid();
}
