#include "func.h"

typedef struct{
	int tickets;
	pthread_mutex_t mutex;
	pthread_cond_t cond;
}Data;

void* salewindow1(void *p)
{
	Data* t=(Data*)p;
	int i=0;
	int ret;
	while(1)
	{
		pthread_mutex_lock(&t->mutex);
		if(t->tickets>0)
		{
			printf("I am salewindow1, there exists %d tickets.\n",t->tickets);
//			printf("I am salewindow1,I will sale %d\n",t->tickets);
			t->tickets--;
			i++;
			//if(t->tickets==0)
			//{
			////	ret=pthread_cond_signal(&t->cond);
			////	printf("pthread_cond_signal ret=%d\n",ret);
			//}
			//printf("I am salewindow1,I have saled %d\n",t->tickets);
			printf("I am salewindow1, I have sold  %d tickets.\n",i);
			pthread_mutex_unlock(&t->mutex);
//			sleep(1);
		}else{
			ret=pthread_cond_signal(&t->cond);
			printf("pthread_cond_signal ret=%d\n",ret);
			pthread_mutex_unlock(&t->mutex);
			//printf("I am salewindow1,I have saled %d\n",i);
			printf("I am salewindow1. Finally, I have saled %d in total.\n",i);
			break;
		}
	}
}

void* salewindow2(void *p)
{
	Data* t=(Data*)p;
	int i=0;
	int ret;
	while(1)
	{
		pthread_mutex_lock(&t->mutex);
		if(t->tickets>0)
		{
			printf("I am salewindow2, there exists %d tickets.\n",t->tickets);
		//	printf("I am salewindow2,I will sale %d\n",t->tickets);
			t->tickets--;
			i++;
			if(t->tickets==0)
			{
				ret=pthread_cond_signal(&t->cond);
				printf("pthread_cond_signal ret=%d\n",ret);
			}
			//printf("I am salewindow2,I have saled %d\n",t->tickets);
			//printf("I am salewindow1, there exists %d tickets.\n",t->tickets);
			printf("I am salewindow2, I have sold  %d tickets.\n",i);
			pthread_mutex_unlock(&t->mutex);
//			sleep(1);
		}else{
			pthread_mutex_unlock(&t->mutex);
			//printf("I am salewindow2,I have saled %d\n",i);
			//printf("I am salewindow1,I have saled %d in total.\n",i);
			printf("I am salewindow2. Finally, I have saled %d in total.\n",i);
			break;
		}
	}
}

int main()
{
	pthread_t pthid1,pthid2;
	Data t;
	t.tickets=40;
	pthread_mutex_init(&t.mutex,NULL);
	pthread_cond_init(&t.cond,NULL);
	pthread_create(&pthid1,NULL,salewindow1,&t);
	pthread_create(&pthid2,NULL,salewindow2,&t);
	pthread_mutex_lock(&t.mutex);
	if(t.tickets>0)
	{
		printf("I will wait\n");
		pthread_cond_wait(&t.cond,&t.mutex);
	}
	t.tickets=20;
	pthread_mutex_unlock(&t.mutex);
	pthread_join(pthid1,NULL);
	pthread_join(pthid2,NULL);
	printf("the number of tickets was reset again to :%d\n",t.tickets);
	return 0;
}
