#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <pthread.h>
#include <unistd.h>

void *doSendMsg(void *c)
{
	char* cmd = c;
	FILE *f_snd = popen(cmd,"w");
}
void *doReadMsg(void *null)
{

	FILE *f_rcv = popen("./msgrcv ./msgsnd 0","w");
}
int main()
{
    int rc;
    pthread_t th_snd;
	pthread_t th_rd;
	pthread_attr_t attr_snd;
	
	pthread_attr_init(&attr_snd);
	pthread_attr_setdetachstate(&attr_snd, PTHREAD_CREATE_JOINABLE);
	
	rc = pthread_create(&th_snd, &attr_snd, doSendMsg, "./msgsnd ./msgsnd 1 message");
	if (rc) {
		perror("Erreur lors de la création du thread");
		exit(-1);
	}
	/* Wait for the thread */
	rc = pthread_join(th_snd, NULL);
	if (rc) {
		perror("Erreur lors du join");
		exit(EXIT_FAILURE);
	}
	
	rc = pthread_create(&th_rd, &attr_snd, doReadMsg,NULL);
	
	/* Wait for the thread */
	rc = pthread_join(th_rd, NULL);
	if (rc) {
		perror("Erreur lors du join");
		exit(EXIT_FAILURE);
	}
   
    pthread_attr_destroy(&attr_snd);
	
	pthread_exit(NULL);
	
    return 0;
}
