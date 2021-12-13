// hello_signal.c 
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// global variable 
int x = 0;

//signal handler
void handler(int signum) { 
	printf("Hello World!\n");
	x = 1;
	alarm(1); //Schedule a SIGALRM for 1 second
}

int main(int argc, char * argv[]) {
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  alarm(1); //Schedule a SIGALRM for 1 second

  while(1) {
    while(x == 0); //busy wait for signal to be delivered
    printf("Turing was right!\n");
    x = 0;
  }

  return 0; //never reached
}