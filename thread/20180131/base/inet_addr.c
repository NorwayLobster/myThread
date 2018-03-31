#include "func.h"

int main(int argc,char *argv[])
{
	if(argc!=2)
	{
		printf("error args\n");
		return -1;
	}
	int ret;
	printf("addr.s_addr=%x\n",inet_addr(argv[1]));
	return 0;
}
