#include "func.h"

int main(int argc,char *argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	bzero(&ser,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));//一定要用htons
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret=connect(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	ret=send(sfd,"nihaoshuai",10,0);
	if(-1==ret)
	{
		perror("send");
		return -1;
	}
	char buf[128]={0};
	ret=recv(sfd,buf,sizeof(buf),0);
	if(-1==ret)
	{
		perror("recv");
		return -1;
	}
	printf("I am client,%s,ret=%d\n",buf,ret);
	close(sfd);
	return 0;
}
