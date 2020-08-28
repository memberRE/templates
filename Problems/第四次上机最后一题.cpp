#include<stdio.h>
int n, a[12];
int check()
{
	for(int i=1;i<=n;i++)
		if(!(a[i]&1))	return 0;
	return 1;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=66666;i++)
	{
		int cnt=0;
		if(check())
			for(int j=1;j<=n;j++)
				a[j]=3*a[j]+1;
		else
			for(int j=1;j<=n;j++)
				a[j]=a[j]&1?(a[j]>>1)+1:a[j]>>1;//(a[j]>>1)+1;
		for(int j=1;j<=n;j++)
		{
			printf("%d ",a[j]);
			if(a[j]==1)
				cnt++;
		}	
		printf("\n");
		if(cnt==n)
			break;
	}
	return 0;
}

