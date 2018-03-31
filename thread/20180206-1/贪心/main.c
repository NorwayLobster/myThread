#include <stdio.h>
#include <stdlib.h>

typedef int(*pt)[4];
int compare(const void* p1,const void* p2)
{
	int (*a1)[4]=(pt)p1;
	int (*a2)[4]=(pt)p2;
	return (*a2)[3]-(*a1)[3];
}

int main()
{
	int money,n;
	int i;
	int t;
	int a[1000][4];
	scanf("%d%d",&money,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d",&a[i][0],&a[i][1],&a[i][2]);
		a[i][3]=money/a[i][0]*a[i][1]+a[i][2];
	}
	qsort(a,n,16,compare);
	i=0;
	t=0;
	while(i<n)
	{
		if(money<a[i][0])
		{
			i++;
			continue;
		}
		t=t+money/a[i][0]*a[i][1]+a[i][2];
		money=money%a[i][0];
		i++;
	}
	printf("%d\n",t);
	system("pause");
}