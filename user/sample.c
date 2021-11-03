#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"

int
main(int argc, char *argv[])
{ 
  int x = 5;
  int y = settickets(x);

  // if(fork() == 0){
  //   printf(1, "child pid is %d", getpid());
  // } else{
  //   printf(1, "parent pid is %d", getpid());
  // }
  

  if(fork() == 0){
    struct pstat child;
    if(getpinfo(&child) == 0){
      printf(1, " pid: %d, tickets: %d\n", child.pid[3], child.tickets[3]);
      
    }else{
      printf(1, "getpinfo failed at child");
    }
    exit();
  }else{
    struct pstat child;
    if(getpinfo(&child) == 0){
      printf(1, " pid: %d, tickets: %d\n", child.pid[2], child.tickets[2]);
      
    }else{
      printf(1, "getpinfo failed at parent");
    }
  }

  exit();
  return y;
}
