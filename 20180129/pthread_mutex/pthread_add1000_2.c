#include "func.h"
#define N 50000000


typedef struct{
	pthread_mutex_t mutex;
	long total;
}data;

void* thread_func(void *p)
{
	printf("i am child thread");
	data *t=(data*)p;
	int i;
	for(i=0;i<N;i++)
	{
		pthread_mutex_lock(&t->mutex);
		t->total=t->total+1;
		pthread_mutex_unlock(&t->mutex);
	}
	pthread_exit(NULL);
}
//main线程最后退出
int main()
{
	pthread_t pthid;
	int ret;
	data t;
	ret=pthread_mutex_init(&t.mutex,NULL);
	if(ret!=0)
	{
		printf("pthread_mutex_init ret=%d\n",ret);
		return -1;
	}
	t.total=0;
	ret=pthread_create(&pthid,NULL,thread_func,(void*)&t);
	if(ret!=0)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	int i;
	printf("i am child thread");
	for(i=0;i<N;i++)
	{
		pthread_mutex_lock(&t.mutex);
		t.total=t.total+1;
		pthread_mutex_unlock(&t.mutex);
	}
	pthread_join(pthid,NULL);
	printf("I am main thread,t.total=%ld\n",t.total);
	pthread_mutex_destroy(&t.mutex);
	if(ret!=0)
	{
		printf("pthread_destroy ret=%d\n",ret);
		return -1;
	}
	return 0;
}
