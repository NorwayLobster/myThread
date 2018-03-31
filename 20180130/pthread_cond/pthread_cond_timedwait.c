#include "func.h"

typedef struct{
	pthread_cond_t cond;
	pthread_mutex_t mutex;
}data;

void* thread_func(void *p)
{
	data *t=(data*)p;
	int ret;
	struct timespec abstime;
	bzero(&abstime,sizeof(abstime));
	abstime.tv_sec=time(NULL)+5;
	printf("I am thread1,I will wait\n");
	pthread_mutex_lock(&t->mutex);
	ret=pthread_cond_timedwait(&t->cond,&t->mutex,&abstime);
	pthread_mutex_unlock(&t->mutex);
	printf("I am thread1,I wakeup,ret=%d\n",ret);
	pthread_exit(NULL);
}

int main()
{
	pthread_t pthid;
	data t;
	int ret=pthread_cond_init(&t.cond,NULL);
	if(ret!=0)
	{
		printf("pthread_cond_init failed ret=%d\n",ret);
		return -1;
	}
	pthread_mutex_init(&t.mutex,NULL);
	pthread_create(&pthid,NULL,thread_func,&t);
	sleep(3);
	pthread_cond_signal(&t.cond);//发信号，让条件成立
	pthread_join(pthid,NULL);
	printf("I am main thread\n");
	return 0;
}
