#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main()
{
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	int las=0,i;
	for( i=2;i<=n;i++)
		las=(las+m)%i;
	printf("%d",(las+q)%n);
	return 0;
}
