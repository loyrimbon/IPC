CC=gcc
CFLAGS= -Wall -pedantic
msgsnd : libIPC_uzi.o msgsnd.o
	$(CC) $(CFLAGS) lib_IPC_uzi.o msgsnd.o -o msgsnd
libIPC_uzi.o : libIPC_uzi.c libIPC_uzi.h
	$(CC) $(CFLAGS) -c libIPC_uzi.c
msgsnd.o : msgsnd.c libIPC_uzi.h
	$(CC) $(CFLAGS) -c msgsnd.c
clean :
	rm *.o msgsnd