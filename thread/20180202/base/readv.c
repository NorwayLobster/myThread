#include "func.h"

int main()
{
	struct iovec iov[2];
	char buf[10]={0};
	char buf1[10]={0};
	iov[0].iov_base=buf;
	iov[0].iov_len=5;
	iov[1].iov_base=buf1;
	iov[1].iov_len=5;
	int fd=open("file1",O_RDWR);
	readv(fd,iov,2);
	printf("buf=%s,buf1=%s\n",buf,buf1);
	close(fd);
}
