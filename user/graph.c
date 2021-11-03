#include "types.h"
#include "stat.h"
#include "user.h"
#include "pstat.h"
#define check(exp, msg) if(exp) {} else {\
   printf(1, "%s:%d check (" #exp ") failed: %s\n", __FILE__, __LINE__, msg);\
   exit();}
#define PROC 7

void spin(int tickets)
{
//printf(1, "\nnote this value, should be just 3\n");
	struct pstat st;
	int i = 0;
  int j = 0;
  int k = 0;
  int z = 0;
	for(i = 0; i < 100; ++i)
	{	//printf(1, "every time its less than 50\n");
		for(j = 0; j < 10000000; ++j)
		{
      		k = j % 10;
      		k = k + 1;
    	}

		check(getpinfo(&st) == 0, "getpinfo");
		//printf(1, "A check point reached ----------------- \n");
	 	//  printf(1, "\n**** PInfo ****\n");
		if(tickets == 30) {
	    	//printf(1, "A check point reached\n");
			for(z = 0; z < NPROC; z++) {
	       
		   		if(st.tickets[z] == 10 || st.tickets[z] == 20 || st.tickets[z] == 30){
	          		printf(1, "%d ",st.ticks[z]);
			  	}
	       
		}
		   printf(1, "\n");

		}
	}
}


int
main(int argc, char *argv[])
{
   
   printf(1,"Spinning...\n");
   printf(1, " 10tickets 20tickets 30tickets\n");
	check(settickets(1000) == 0, "error in setting tickets");	
	if(fork() == 0){
		check(settickets(10) == 0, "error in setting tickets");
		spin(10);
		exit();
	}else{
		if(fork() == 0){
			check(settickets(20) == 0, "error in setting tickets");
			spin(20);
			exit();
		} else {
			if(fork() == 0){
				check(settickets(30) == 0, "error in setting tickets");
				spin(30);
				exit();
			}
		}
	}
	while(wait() > 0);
   //sleep(500);
   //spin();
  
   printf(1, "Should print 1 then 2");
   exit();
}
