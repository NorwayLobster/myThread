#include "func.h"

void set_nonblock(int fd)
{
	int status;
	status=fcntl(fd,F_GETFL);
	status=status|O_NONBLOCK;
	int ret=fcntl(fd,F_SETFL,status);
}

int main()
{
	char buf[128]={0};
	sleep(5);
	set_nonblock(STDIN_FILENO);
	int ret;
	ret=read(STDIN_FILENO,buf,sizeof(buf));
	printf("ret=%d,%s,errno=%d",ret,buf,errno);
	return 0;
}
