#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
int n,top1,top2;
int stk1[MAX],stk2[MAX];
int a[MAX],b[MAX];
int main()
{
	while(scanf("%d",&n)!=EOF)
	{
		top1=top2=0;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;i++)
			scanf("%d",&b[i]);
		for(int i=1;i<=n;i++)
		{
			while(top1 and a[stk1[top1-1]]>a[i])
				top1--;
			while(top2 and b[stk2[top2-1]]>b[i])
				top2--;
			if(top1!=top2)
			{
				printf("%d\n",i-1);
				break;
			}
			else
				stk1[top1++]=i,stk2[top2++]=i;
		}
		if(stk1[top1-1]==n)
			printf("%d\n",n);
	}
	return 0;
}
