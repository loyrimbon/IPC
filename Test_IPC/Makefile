CC=gcc
CFLAGS= -Wall -pedantic
test_IPC : test_IPC.o
    $(CC) test_IPC.o -o test_IPC
msgrcv : libIPC_uzi.o msgrcv.o
    $(CC) libIPC_uzi.o msgsnd.o -o msgsnd
msgsnd : libIPC_uzi.o msgsnd.o
	$(CC) libIPC_uzi.o msgsnd.o -o msgsnd
libIPC_uzi.o : libIPC_uzi.c libIPC_uzi.h
	$(CC) -c libIPC_uzi.c
msgsnd.o : msgsnd.c libIPC_uzi.h
	$(CC) -c msgsnd.c
msgrcv.o : msgrcv.c libIPC_uzi.h
    $(CC) -c msgrcv.c
test_IPC.o : test_IPC.c
    $(CC) -c test_IPC.c
clean :
	rm *.o msgsnd
