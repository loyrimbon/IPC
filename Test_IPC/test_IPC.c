#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>

void *read_mq(void* null)
{
	
}
void *write_mq(void* null)
{
	
}
int main()
{
    int rc, i;
    pthread_t tid;

    rc = pthread_create(&tid, &attr, read_mq, NULL);
    if(rc) {
		perror("Erreur lors de la création du thread");
		exit(-1);
    }

    return 0;
}