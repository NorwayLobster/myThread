#include "func.h"
#define N 50000000

void* thread_func(void *p)
{
	long *t=(long*)p;
	int i;
	for(i=0;i<N;i++)
	{
		*t=*t+1;
	}
	pthread_exit(NULL);
}
//main线程最后退出
int main()
{
	pthread_t pthid;
	int ret;
	long t=0;
	ret=pthread_create(&pthid,NULL,thread_func,(void*)&t);
	if(ret!=0)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	int i;
	for(i=0;i<N;i++)
	{
		t=t+1;
	}
	pthread_join(pthid,NULL);
	printf("I am main thread,t=%ld\n",t);
	return 0;
}
