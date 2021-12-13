#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//Initialize a counter variable
int c = 0;


void start(int signum){
  c++; // :)
  printf("%d seconds\n", c);
  alarm(1);  
}

void stop(int signum){
  printf("\nRan for %d seconds\n", c);
  exit(0);
}

int main(int argc, char * argv[]){
  signal(SIGALRM, start);
  signal(SIGINT, stop);
  
  alarm(1);
  while(1);
  
  return 0;
  
}