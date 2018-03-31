#include "func.h"

void* thread_func(void *p)
{
	printf("I am child thread\n");
	while(1);
}

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	pthread_t pthid;
	int ret;
	int num=atoi(argv[1]);
	int i;
	struct timeval start,end;
	bzero(&start,sizeof(start));
	bzero(&end,sizeof(end));
	gettimeofday(&start,NULL);
	for(i=0;i<num;i++)
	{
		ret=pthread_create(&pthid,NULL,thread_func,NULL);
	}
	gettimeofday(&end,NULL);
	printf("%ld\n",(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
	while(1);
}
