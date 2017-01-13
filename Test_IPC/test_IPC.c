#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>



int main()
{
    FILE *f_snd = popen("./msgsnd","r");
    FILE *f_rcv = popen("./msgrcv","r");
    return 0;
}