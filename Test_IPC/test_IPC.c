#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <unistd.h>


int main()
{
    
    
    FILE *f_snd = popen("./msgsnd ./msgsnd 1 message","w");
   // sleep(15);
    FILE *f_rcv = popen("./msgrcv ./msgsnd 0","w");
    
    char buf[256];
   
    while(fgets(buf, sizeof(buf), f_snd))
    {
        
        fputs(buf,stdout);
    }
    pclose(f_snd);
    pclose(f_rcv);
    
    return 0;
}
