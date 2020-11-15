///
/// @file    createthread.c
/// @author  lemon(haohb13@gmail.com)
/// @date    2018-03-31 01:47:01
///

#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void *ThreadFunc(void *pArg) {
	int i = 0;
	for(; i<10; i++)//参数的值为 123
	{
		printf("Hi,I'm child thread,arg is:%d\n", *pArg);
		sleep(1);
	}
		pthread_exit(NULL); 
}

int main()
{
	pthread_t thdId;
	pthread_create(&thdId, NULL, ThreadFunc, (void *)123 ); int i = 0;
	for(; i<10; i++)
	{
	printf("Hi,I'm main thread,child thread id is:%d\n", thdId);
	sleep(1);
	}
	return 0;
}
