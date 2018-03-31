#include "func.h"

void sig(int signum)
{
}
int main()
{
	signal(SIGALRM,sig);
	alarm(10);//启动定时器，3秒后向当前进程发送信号
	pause();
	return 0;
}
