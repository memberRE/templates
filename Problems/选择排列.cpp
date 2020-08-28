#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int n,m,no[10];
int vztd[10];
void A(int l,int num)
{
	if(num==0)	
	{
		for(int i=0;i<m;i++)
			printf("%d ",no[i]);
		printf("\n");
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vztd[i])
		{
			no[m-num]=i;
			vztd[i]=1;
			A(l,num-1);
			vztd[i]=0;
		}
	}
}
int main()
{
	cin>>n>>m;
	memset(vztd,0,sizeof(vztd));
	memset(no,0,sizeof(no));
	A(n,m);
	return 0;
}

