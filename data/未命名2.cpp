#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAX=100003;
int dir[MAX],ls[MAX],rs[MAX]/*,num[MAX]*/,head;
void add(int num,int stu,int lr)// 0 left ;;1 right
{
	if(lr==0)
	{
		rs[num]=stu;
		ls[num]=ls[stu];
		if(ls[num]==0)
			head=num;
		ls[stu]=num;
		rs[ls[num]]=num;
	}
	if(lr==1)
	{
		ls[num]=stu;
		rs[num]=rs[stu];
		rs[stu]=num;
		ls[num[rs]]=num;
	}
}
void print(int node)
{
	if(node==0)	return ;
	if(dir[node]==-1)
		printf("%d ",node);
	print(rs[node]);
	return ;
}
int main()
{
	int n;
	scanf("%d",&n);
	head=1;
	memset(dir,-1,sizeof(dir));
	for(int i=2;i<=n;i++)
	{
		int k,l;
		scanf("%d%d",&k,&l);
		add(i,k,l);
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		int k;
		scanf("%d",&k);
		dir[k]=0;
	}
	print(head );
	return 0;
}

