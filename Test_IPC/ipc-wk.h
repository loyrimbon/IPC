#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#ifndef __IPC_WK__
#define __IPC_WK__

/** File must exist and reachable **/
#define IPC_NAME	"/tmp/ipc-name"

#define DEFAULT_IPC_PERM	( S_IRGRP | S_IWGRP )

typedef enum _IPC_CODE { IPC_ERROR, IPC_SUCCESS } ipc_code;

/**
 * DeleteIPC: delete IPC (owner only)
 * return : IPC_ERROR if can't remove IPC
 **/
ipc_code DeleteIPC();

/**
 * CreateIPC : create IPC with default perm DEFAULT_IPC_PERM
 * return : IPC_ERROR if IPC already exist
 **/
ipc_code CreateIPC();
 
/**
 * GetInfoIPC : return information about previously openned IPC
 * return : NULL on failure
 **/
ipc_code GetInfoIPC( struct msqid_ds * stat );

/**
 * GetSystemInfoIPC : return system-wide information about IPC
 * return : IPC_ERROR  on error
 **/
ipc_code GetSystemInfoIPC( struct msginfo * info );

/**
 * WriteIPC : write a message to the IPC
 * return : IPC_ERROR can't write to IPC
 **/
ipc_code WriteIPC( char * msg );
 
/**
 * ReadIPC : read a message from the IPC
 * return : IPC_ERROR can't read the IPC
 **/
ipc_code ReadIPC( char ** msg );

#endif