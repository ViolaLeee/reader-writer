#include<stdio.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include<semaphore.h>
#include<pthread.h>


sem_t db,rc;
int readcount;
sem_t rmutex,wmutex;
void *writer(int *buffer){
//    printf ("write ::%d\n", *buffer);

//    while(1) {
	sem_wait(&db);
	sem_wait(&rc);
	sem_post(&db);

	printf("write ::%d\n", *buffer);
	*buffer+=1;

	sem_wait(&db);
	sem_post(&rc);
	sem_post(&db);
//             }
    return NULL;
}

