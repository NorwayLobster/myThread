#include "func.h"

void cleanup(void *p)
{
	printf("I am cleanup,%ld\n",(long)p);
}

void* thread_func(void *p)
{
	printf("I am child thread\n");
	p=malloc(20);
	pthread_cleanup_push(cleanup,(void*)1);
	pthread_cleanup_push(cleanup,(void*)2);
	sleep(2);
	printf("after sleep,I am child thread\n");
	pthread_exit(NULL);
	printf("i went here");
	pthread_cleanup_pop(1);
	pthread_cleanup_pop(1);
}
//main线程最后退出
int main()
{
	pthread_t pthid;
	int ret;
	ret=pthread_create(&pthid,NULL,thread_func,NULL);
	if(ret!=0)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
//	sleep(1);
	pthread_cancel(pthid);
	pthread_join(pthid,NULL);
	printf("I am main thread\n");
	return 0;
}
