#include<stdio.h>
#include <unistd.h>
#include <time.h>
#include<semaphore.h>
#include<pthread.h>


extern  sem_t db,rc;
extern int readcount;
extern sem_t rmutex,wmutex;
void *reader(int *buffer){

//    printf("\nReader Inside..%d\n", *buffer);
//    sleep (3);

    while(1) {
	sem_wait(&db);
	if (readcount==0)
	    sem_wait(&rc);
	readcount+=1;
	sem_post(&db);

	printf("\nReader Inside..%d\n", *buffer);

	sem_wait(&db);
	readcount-=1;
	if (readcount==0)
	    sem_post(&rc);
	sem_post(&db);
	sleep(3);
             }  
    return NULL;  
}

