#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include "libIPC_uzi.h"
/**
#define IPC_READ	"/tmp/squid_data"
#define IPC_BLACK_LIST	"/tmp/black_data"
*/

/**
 * @brief 
 * @param ipc_name 
 * @return IPC key or -1 on failure
 */
key_t getIPCKey(char* ipc_name)
{
	return ftok(ipc_name,0);
}
/**
 * @brief 
 * @param key
 * @return file message id or set ERRNO on failure
 */
int createIPC(key_t key)
{
	int file;
	file = msgget(key,IPC_CREAT |0600);
	return file;
}
/**
 * @brief 
 * @param file
 * @param message
 * @return 0 on success -1 on failure 
 */
int writeIPC(int file,char* message)
{
	msgsnd(file,message,256,0);
	return 0;
}
int readIPC(int file,char* message,int size,long type, int attributs)
{
	msgrcv(file, message, size, type, attributs);
	return 0;
}
