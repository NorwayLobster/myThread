#include "func.h"

void* thread_func(void* p)
{
	printf("I am child\n");
	int ret;
//	while(1);
	sleep(4);
	pthread_exit(NULL);
}

int main()
{
	pthread_t pthid;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	struct sched_param param;
	int max_p,min_p;
	int policy;
	int ret;
	ret=pthread_attr_getschedpolicy(&attr,&policy);
	if(ret!=0)
	{
		printf("pthread_attr_getschedpolicy %d\n",ret);
		return -1;
	}
	printf("policy=%d\n",policy);
	printf("max_p=%d,min_p=%d\n",max_p,min_p);

	ret=pthread_attr_setschedpolicy(&attr,SCHED_RR);
	if(ret!=0)
	{
		printf("pthread_attr_setschedpolicy failed ,ret=%d\n",ret);
		return -1;
	}
	param.sched_priority=51;
	pthread_attr_setschedparam(&attr,&param);
	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);	//设置继承性

	pthread_create(&pthid,&attr,thread_func,NULL);
	pthread_join(pthid,(void**)&ret);
	printf("ret:%d\n",ret);
//	while(1);
}
