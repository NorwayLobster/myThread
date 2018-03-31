#include "func.h"

typedef struct{
	long mtype;
	char buf[64];
}MSG;
int main()
{
	int msgid=msgget(1234,IPC_CREAT|0600);
	if(-1==msgid)
	{
		perror("msgget");
		return -1;
	}
	MSG msg;
	bzero(&msg,sizeof(msg));
	msg.mtype=1;
	int i=10;
	memcpy(msg.buf,&i,sizeof(i));//把整型数的4个字节放到buf里
	int ret=msgsnd(msgid,&msg,sizeof(int),0);
	if(-1==ret)
	{
		perror("msgsnd");
		return -1;
	}
	bzero(&msg,sizeof(msg));
	ret=msgrcv(msgid,&msg,sizeof(msg.buf),1,0);
	if(-1==ret)
	{
		perror("msgrcv");
		return -1;
	}
	printf("ret=%d\n",ret);
	printf("buf=%d\n",*(int*)msg.buf);
	return 0;
}
