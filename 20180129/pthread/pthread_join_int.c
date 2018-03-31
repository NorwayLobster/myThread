#include "func.h"

void* thread_func(void *p)
{
	printf("I am child thread\n");
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
	int i;
	ret=pthread_join(pthid,(void**)&i);
	if(ret!=0)
	{
		printf("pthread_join ret=%d\n",ret);
		return -1;
	}
	printf("I am main thread,i=%d\n",i);
	return 0;
}
