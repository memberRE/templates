#include<cstdio>
#include<algorithm>
#include<iostream>
#include<map>
#include<cstring>
using namespace std;
map<int,int> ma;
int a[1003],b[1003];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			ma[a[i]+b[j]]=1;
		}
	cout<<ma.size()<<endl;
	return 0;
}
