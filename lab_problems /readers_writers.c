#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>

sem_t mutex,wrt;
int readcount;



void *writer(void *param)
{
	int i=(int)param;
	sem_wait(&wrt);
	printf("\nWRITING START: %d\n",i);

	printf("\nWRITING END: %d\n",i);
	sem_post(&wrt);
	
}
void *reader(void *param)
{
	int i=(int)param;
	sem_wait(&mutex);
	readcount++;
	if(readcount==1)
		sem_wait(&wrt);
	sem_post(&mutex);

	printf("\nREADING START: %d\n",i);

	printf("\nREADING END: %d\n",i);

	sem_wait(&mutex);
	readcount--;
	if(readcount==0)
		sem_post(&wrt);
	sem_post(&mutex);


}
int main()
{
	readcount=1;
	pthread_t rd[50],wr[50];
	sem_init(&wrt,1,1);
	sem_init(&mutex,0,1);
	int i,j;
	for(i=0;i<50;i++)
	pthread_create(&rd[i],0,&writer,(void *)i);

	for(i=0;i<50;i++)
	pthread_create(&wr[i],0,&reader,(void *)i);

	for(i=0;i<50;i++)
	pthread_join(rd[i],0);

	for(i=0;i<50;i++)
	pthread_join(wr[i],0);

	sem_destroy(&wrt);
	sem_destroy(&mutex);

}