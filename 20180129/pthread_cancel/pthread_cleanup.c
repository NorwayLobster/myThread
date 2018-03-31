#include "func.h"

void cleanup(void *p)
{
	printf("I am cleanup\n");
	free(p);
}

void* thread_func(void *p)
{
	printf("I am child thread\n");
	p=malloc(20);
	pthread_cleanup_push(cleanup,p);
	sleep(2);
	printf("after sleep,I am child thread\n");
	pthread_cleanup_pop(1);
	return NULL;
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
//	sleep(3);
	pthread_cancel(pthid);
//	pthread_join(pthid,NULL);
	printf("I am main thread\n");
	return 0;
}
