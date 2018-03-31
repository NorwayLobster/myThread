#include "func.h"
#define N 50000000


typedef struct{
	pthread_mutex_t mutex;
	long total;
}data;

void* thread_func(void *p)
{
	data *t=(data*)p;
//	pthread_mutex_lock(&t->mutex);
	while(1);
	pthread_exit(NULL);
}
//main线程最后退出
int main()
{
	pthread_t pthid;
	int ret;
	data t;
	pthread_mutexattr_t  mattr;
	pthread_mutexattr_init(&mattr);
	pthread_mutexattr_settype(&mattr,PTHREAD_MUTEX_ERRORCHECK);
	ret=pthread_mutex_init(&t.mutex,&mattr);
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
	ret=pthread_mutex_lock(&t.mutex);
	printf("I am main thread,ret=%d\n",ret);
	ret=pthread_mutex_lock(&t.mutex);
	printf("I am main thread,ret=%d\n",ret);
	pthread_mutex_destroy(&t.mutex);
	if(ret!=0)
	{
		printf("pthread_destroy ret=%d\n",ret);
		return -1;
	}
	return 0;
}
