#include "func.h"

//void* 变为其他类型指针，必须进行强制类型转换
void* thread_func(void *p1)
{
	printf("I am child thread\n");
	strcpy((char*)p1,"hello");
	pthread_exit(NULL);
}
//main线程最后退出
int main()
{
	pthread_t pthid;
	int ret;
	char *p=(char*)malloc(20);
	ret=pthread_create(&pthid,NULL,thread_func,p);
	if(ret!=0)
	{
		printf("pthread_create ret=%d\n",ret);
		return -1;
	}
	sleep(1);
	printf("I am main thread,p=%s\n",p);
	return 0;
}
