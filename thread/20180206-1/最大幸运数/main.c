#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n;
	int *p;
	int i,j,luck,second;
	scanf("%d",&n);
	p=(int*)malloc(sizeof(int)*n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&p[i]);
	}
	luck=p[0]^p[1];
	for(i=0;i<n-1;i++)
	{
		second=p[i+1];
		if(p[i]^second>luck)
		{
			luck=p[i]^second;
		}
		for(j=i+2;j<n;j++)
		{
			if(p[j]>second && p[i]^p[j]>luck)
			{
				luck=p[i]^p[j];
			}
		}
	}
	printf("%d\n",luck);
	system("pause");
}