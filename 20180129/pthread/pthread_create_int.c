#include "func.h"

void* thread_func(void *p)
{
	printf("I am child thread %ld\n",(long)p);
	pthread_exit(NULL);
}
//main线程最后退出
int main()
{
	pthread_t pthid;
	int ret;
	ret=pthread_create(&pthid,NULL,thread_func,(void*)1);
	if(ret!=0)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	ret=pthread_create(&pthid,NULL,thread_func,(void*)2);
	sleep(1);
	printf("I am main thread\n");
	return 0;
}
