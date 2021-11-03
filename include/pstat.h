/* This code has been added by akshay and jagan with netid's akj200008 and jxm210003 respectively
** Declaring the structure for proc statistics as defined in the assignment
*/
#ifndef _PSTAT_H_ 
#define _PSTAT_H_ 

#include "param.h" 
 
struct pstat { 
  int inuse[NPROC];   // whether this slot of the process table is in use (1 or 0) 
  int tickets[NPROC]; // the number of tickets this process has 
  int pid[NPROC];     // the PID of each process  
  int ticks[NPROC];   // the number of ticks each process has accumulated  
}; 
 
#endif // _PSTAT_H_

/* End of code added */