#include "ipc-wk.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <bsd/string.h>

/** IPC id **/
static int id = 0;

/** IPC key **/
static key_t key = 0;

#define MAX_SIZE	255

typedef struct _mbuf
{
	long mtype;
	char mtext[ 255 ];
} mbuf;

/**
 * ExtractKey : extract the key value from IPC name
 * return : -1 on failure
 **/
static key_t doExtractKey()
{
	return ftok( IPC_NAME, 42 );
}

static ipc_code doOpenIPC( int flag )
{
	if( ( key = doExtractKey() ) == -1 )
	{
		return IPC_ERROR;
	}
	
	if ( ( id = msgget( key, flag ) ) == -1 )
	{
		return IPC_ERROR;
	} 
	
	return IPC_SUCCESS;
}

ipc_code CreateIPC()
{
	return doOpenIPC( IPC_CREAT | IPC_EXCL | DEFAULT_IPC_PERM );
}

 static ipc_code OpenIPC()
 {
	 return doOpenIPC( 0 );
 }
 
 ipc_code GetInfoIPC( struct msqid_ds * stat )
 {
	if ( stat == NULL )
	{
		return IPC_ERROR;
	}
	
	if ( id == 0 )
	{
		OpenIPC();
	}	 
	
	if ( msgctl( id, IPC_STAT, stat ) == -1 )
	{
		return IPC_ERROR;
	}
	
	return IPC_SUCCESS;
 }
 
ipc_code GetSystemInfoIPC( struct msginfo * info )
 {
	if ( info == NULL )
	{
		return IPC_ERROR;
	}
	
	if ( msgctl( 1, IPC_INFO, (struct msqid_ds *) info ) == -1 )
	{
		return IPC_ERROR;
	}
	
	return IPC_SUCCESS;
 }

/**
 * To perform an IPC_SET or IPC_RMID control command, a process must have:
 * - an effective user id of OWNER/CREATOR, or
 * - an effective user id of root (if the system is running with the SUM privilege module), or
 * - the P_OWNER privilege. 
 **/
ipc_code DeleteIPC()
{			
	if( id == 0 )
	{
		OpenIPC();
	}	 
	
	if ( msgctl( id, IPC_RMID, NULL ) == -1 )
	{
		return IPC_ERROR;
	}
	
	return IPC_SUCCESS;
}

ipc_code WriteIPC( char * msg )
{
	mbuf * ipcMsg = NULL;
	
	if ( msg == NULL )
	{
		return IPC_ERROR;
	}
	
	if( id == 0 )
	{
		OpenIPC();
	}	 
	
	if( ( ipcMsg = ( mbuf * ) malloc( sizeof ( mbuf ) ) ) == NULL )
	{
		return IPC_ERROR;
	}
	
	ipcMsg->mtype = 42;
	(void) strlcpy( ipcMsg->mtext, msg, MAX_SIZE );
	// TODO : detect overflow here
	
	if ( msgsnd( id, ipcMsg, strlen( ipcMsg->mtext ) + 1, 0 ) == -1 )
	{
		return IPC_ERROR;
	}
	
	return IPC_SUCCESS;	
}

ipc_code ReadIPC( char ** msg )
{
	mbuf ipcMsg;
	ssize_t len = 0; // length of the message
	
	(void) memset( &ipcMsg, 0, sizeof( mbuf ) );
	
	if ( msg == NULL )
	{ 
		return IPC_ERROR;
	}
	
	if ( *msg == NULL )
	{
		return IPC_ERROR;
	}
	
	if( id == 0 )
	{
		OpenIPC();
	}	 
	
	if( ( len = msgrcv( id, &ipcMsg, MAX_SIZE, 0, 0 ) ) == -1 )
	{
		return IPC_ERROR;
	}
	
	if( ( *msg = ( char * ) malloc( len ) ) == NULL )
	{
		return IPC_ERROR;
	}		
		
	(void)memcpy( *msg, ipcMsg.mtext, len );
	
	return IPC_SUCCESS;
}