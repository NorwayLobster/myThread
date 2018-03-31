#include "func.h"

void get_salt(char* salt,char* ciphertext)
{
	int i,j;
	for(i=0,j=0;ciphertext[i]!=0&&j!=3;i++)
	{
		if('$'==ciphertext[i])
		{
			j++;
		}
	}
	strncpy(salt,ciphertext,i-1);
}

int main(int argc,char* argv[])
{
	struct spwd *sp;
	char *passwd;
	char salt[512]={0};
	if(argc!=2)
	{
		printf("error args ./a.out usrname\n");
		return -1;
	}
	passwd=getpass("请输入密码");
	sp=getspnam(argv[1]);
	if(NULL==sp)
	{
		perror("getspnam");
		return -1;
	}
	puts(sp->sp_pwdp);
	get_salt(salt,sp->sp_pwdp);
	puts(salt);
	char *p=crypt(passwd,salt);
	puts(p);
	if(strcmp(sp->sp_pwdp,p)==0)
	{
		printf("认证通过\n");
	}else{
		printf("认证失败\n");
	}
	return 0;
}
