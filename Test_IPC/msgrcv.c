#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <unistd.h>
#include "libIPC_uzi.h"
//test commit


int main (int argc, char * argv[])
{
	 printf("MSGRCV\n");
    key_t key;
	message_t message;
	int file;
	long type;
	if (argc != 3) {
		fprintf(stderr, "Syntaxe : %s fichier_clé type \n", argv[0]);
		exit(EXIT_FAILURE);
	}
	if ((key = ftok(argv[1], 0)) == -1) {
		perror("ftok");
		exit(EXIT_FAILURE);
	}
    
	if (sscanf(argv[2], "%ld", & type) != 1) {
		fprintf(stderr, "Type invalide");
		exit(EXIT_FAILURE);
	}
	if ((file = msgget(key, IPC_CREAT | 0600)) == -1) {
		perror("msgget");
		exit(EXIT_FAILURE);
	}
	do
    {
        sleep(3);
    if (msgrcv(file, (void *) & message, 256, type, 0) >= 0)
    {
        if(message.type!=-2)
            fprintf(stdout, "(%ld) %s \n", message.type, message.texte);
    }
    else
        perror("msgrcv");
    }while(strcmp(message.texte,"FIN")!=0);
    
    removeIPC(file);
           
	return EXIT_SUCCESS;
}
