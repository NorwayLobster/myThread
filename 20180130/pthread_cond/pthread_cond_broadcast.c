#include "func.h"

typedef struct{
	pthread_cond_t cond;
	pthread_mutex_t mutex;
	short flag;
}data;

void* thread_func(void *p)
{
	data *t=(data*)p;
	int i=t->flag;
	int ret;
	printf("I am thread%d,I will wait\n",i);
	pthread_mutex_lock(&t->mutex);
	ret=pthread_cond_wait(&t->cond,&t->mutex);
	pthread_mutex_unlock(&t->mutex);
	printf("I am thread%d,I wakeup,ret=%d\n",i,ret);
	pthread_exit(NULL);
}

int main()
{
	pthread_t pthid1,pthid2;
	data t;
	int ret=pthread_cond_init(&t.cond,NULL);
	if(ret!=0)
	{
		printf("pthread_cond_init failed ret=%d\n",ret);
		return -1;
	}
	pthread_mutex_init(&t.mutex,NULL);
	t.flag=1;
	pthread_create(&pthid1,NULL,thread_func,&t);
	sleep(1);
	t.flag=2;
	pthread_create(&pthid2,NULL,thread_func,&t);
	sleep(5);
	pthread_cond_broadcast(&t.cond);//发信号，让条件成立
	pthread_join(pthid1,NULL);
	pthread_join(pthid2,NULL);
	printf("I am main thread\n");
	return 0;
}
