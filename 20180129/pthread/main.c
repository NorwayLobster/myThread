#include "func.h"

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int num=atoi(argv[1]);
	int i;
	struct timeval start,end;
	bzero(&start,sizeof(start));
	bzero(&end,sizeof(end));
	gettimeofday(&start,NULL);
	for(i=0;i<num;i++)//创建N个进程的方法
	{
		if(!fork())
		{
			printf("I am child %d\n",getpid());
			while(1);
		}
	}
	gettimeofday(&end,NULL);
	printf("%ld\n",(end.tv_sec-start.tv_sec)*1000000+end.tv_usec-start.tv_usec);
	wait(NULL);
	return 0;
}
