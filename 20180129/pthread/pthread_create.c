#include "func.h"

void* thread_func(void *p)
{
	printf("I am child thread\n");
	pthread_exit(NULL);
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
	sleep(1);
	printf("I am main thread\n");
	return 0;
}
