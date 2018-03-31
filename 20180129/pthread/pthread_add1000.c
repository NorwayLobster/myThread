#include "func.h"
#define N 50000000

int t=0;
void* thread_func(void *p)
{
	printf("I am working thread,t=%d\n",t);
	int i;
	for(i=0;i<N;i++)
	{
		t=t+1;
	}
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
	int i;
	for(i=0;i<N;i++)
	{
		t=t+1;
	}
	pthread_join(pthid,NULL);
	printf("I am main thread,t=%d\n",t);
	return 0;
}
