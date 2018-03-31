#include "func.h"

void sig(int signum)
{
	printf("%d is coming\n",signum);
	exit(1);
}

int main()
{
	if(signal(SIGINT,sig)==SIG_ERR)
	{
		perror("signal");
		return -1;
	}
	//while(1);
	sleep(10);
	return 0;
}
