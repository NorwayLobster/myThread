#include "func.h"

void sig(int signum)
{
	printf("before sleep %d is coming\n",signum);
	sleep(3);
	printf("after sleep %d is coming\n",signum);
}

int main()
{
	if(signal(SIGINT,sig)==SIG_ERR)
	{
		perror("signal");
		return -1;
	}
	signal(SIGQUIT,sig);
	while(1);
	return 0;
}
