#ifndef _LIBIPC_UZI_H
#define _LIBIPC_UZI_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
/**
#define IPC_READ	"/tmp/squid_data"
#define IPC_BLACK_LIST	"/tmp/black_data"
*/
typedef struct _message_t{
	long type;
	char texte [256];
} message_t;

int createIPC(key_t key);
int writeIPC(int file,char* message);
int readIPC(int file,char* message,int size,long type, int attributs);

#endif