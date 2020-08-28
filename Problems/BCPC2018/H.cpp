#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int sum[20];
char a[20];
int tem;
int check(int jkl)
{
	int cnt=0;
	for(int i=1;i<=14;i++)
	{
		if(sum[i]>0)
			cnt++;
		if(cnt==jkl)
		{
			tem=i;
			return 1;
		}
		if(sum[i]==0)
			cnt=0;
	}
	return 0;
}
int main()
{
	int t;
	scanf("%d",&t);
	//getchar();
	while(t--)
	{
		memset(sum,0,sizeof(sum));
		scanf("%s",a);
		for(int i=0;a[i];i++)
		{
			if(a[i]=='A')
				sum[1]++,sum[14]++;
			else if(a[i]=='T')
				sum[10]++;
			else if(a[i]=='J')
				sum[11]++;
			else if(a[i]=='Q')
				sum[12]++;
			else if(a[i]=='K')
				sum[13]++;
			else
				sum[a[i]-'0']++;
		}
		bool flag=check(5);
		if(flag)
		{
			printf("1081\n");
			continue;
		}
		//-----------------------
		int k=0;
		for(int i=1;i<=13;i++)
			if(sum[i]==0)
			{
				sum[i]=1;
				if(i==1)	sum[14]=1;
				k+=check(5);
				sum[i]=0;
				if(i==1)	sum[14]=0;
			}
		if(k==2)
		{
			printf("%d\n",178*2-16);
			continue;
		}
		else if(k==1)
		{
			int h=check(3);
			if(h==0)
			{
				printf("178\n");
				continue;
			}
			if((sum[tem+1]==0 and sum[tem+2]==0 and tem+2<=14) or (tem-4>=1 and sum[tem-4]==0 and sum[tem-3]==0))
				printf("%d\n",178+16);
			else
				printf("178\n");
			continue;
		}
		else
		{
			int tem2=0;
			for(int i=1;i<=13;i++)
			{
				int uio=0;
				if(sum[i]!=0)	continue;
				sum[i]=1;
				if(i==1)
					sum[14]=1;
				for(int j=1;j<=13;j++)
				{
					if(j==i or sum[j]!=0)	continue;
					sum[j]=1;
					if(j==1)
						sum[14]=1;
					uio+=check(5);
					sum[j]=0;
					if(j==1)
						sum[14]=0;
				}
				sum[i]=0;
				if(i==1)
					sum[14]=0;
				if(uio==2)
				{
					printf("32\n");
					tem2=-99999999;
					break;
				}
				if(uio==1)
					tem2++;
			}
			if(tem2>2)
			{
				printf("32\n");
				continue;
			}
			else if(tem2==2)
			{
				printf("16\n");
				continue;
			}
		}
	}
	return 0;
}
