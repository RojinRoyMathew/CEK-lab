#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
void recevier();
void sender();
void main(){
sender();
recevier();
}
void sender(){
void *shared_memory;
char buffer[100];
int shmid;
shmid=shmget((key_t)1222,1024,0666 |IPC_CREAT);
printf("Key of shared memory is : %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("process of shared memory : %p\n",shared_memory);
printf("Enter the data written to shared memory\n");
read(0,buffer,100);
strcpy(shared_memory,buffer);
printf("Data written in shared memory of sender: %s\n",(char *)shared_memory);
}
void recevier(){
void *shared_memory;
int shmid;
shmid=shmget((key_t)1222,1024,0666);
printf("Key of shared memory is : %d\n",shmid);
shared_memory=shmat(shmid,NULL,0);
printf("process of shared memory : %p\n",shared_memory);
printf("Data written in shared memory of recevier: %s\n",(char *)shared_memory);
}
