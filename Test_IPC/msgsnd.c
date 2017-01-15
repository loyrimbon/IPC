#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "libIPC_uzi.h"
/*
typedef struct {
	long type;
	char texte [256];
} message_t;*/
int main (int argc, char * argv [])
{
    printf("MSGSND\n");
    key_t key;
	message_t message;
	int file;
	if (argc != 4)
	{
		fprintf(stderr, "Syntaxe : %s fichier_clé type message \n",argv[0]);
		exit(EXIT_FAILURE);
	}
	//if ((key = ftok(argv[1], 0)) == -1)
	if((key = getIPCKey(argv[1]))==-1)
	{
		perror("ftok");
		exit(EXIT_FAILURE);
	}
	if ((sscanf(argv [2], "%ld", & (message.type)) != 1)|| (message.type <= 0))
	{
		fprintf(stderr, "Type invalide");
		exit(EXIT_FAILURE);
	}
   //if ((file = msgget(key, IPC_CREAT | 0600)) == -1)
	if ((file = createIPC(key)) == -1)
	{
		perror("msgget");
		exit(EXIT_FAILURE);
	}
    for(int i=0;i<10;i++){
        
        
        strncpy (message.texte, argv[3], 255);
        message.texte[255] = '\0';
        
	//ajout du message dans la file
	//if (msgsnd(file, (void *) & message, 256, 0) <0)
           if (writeIPC(file, (void *) & message) <0)
        {
            perror("msgsnd");
            exit(EXIT_FAILURE);
        }
    }
    
    
	return EXIT_SUCCESS;
}
