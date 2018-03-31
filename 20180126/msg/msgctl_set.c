#include "func.h"

int main()
{
	int msgid=msgget(1234,IPC_CREAT|0600);
	if(-1==msgid)
	{
		perror("msgget");
		return -1;
	}
	struct msqid_ds buf;
	bzero(&buf,sizeof(buf));
	int ret=msgctl(msgid,IPC_STAT,&buf);
	if(-1==ret)
	{
		perror("msgctl");
		return -1;
	}
	printf("uid=%d,mode=%o,maxn=%ld\n",buf.msg_perm.uid,buf.msg_perm.mode,buf.msg_qbytes);
	buf.msg_perm.mode=0666;
	ret=msgctl(msgid,IPC_SET,&buf);
	if(-1==ret)
	{
		perror("msgctl1");
		return -1;
	}
	return 0;
}
