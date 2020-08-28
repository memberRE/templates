#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int pic[1002]={-1};
int main()
{
	int n,t;
	cin>>n>>t;
	for(int i=1;i<=n;i++)
		cin>>pic[i];
	for(int i=0;i<t;i++)
	{
		int maxx=0;
		for(int j=1;j<=n;j++)
			if(pic[j]>pic[maxx])
				maxx=j;
		cout<<maxx<<endl;
		int k=pic[maxx]/(n-1);
		int h=pic[maxx]%(n-1);
		for(int j=1;j<=n;j++)
		{
			pic[j]+=k;
			if(h and j!=maxx)
			pic[j]++,h--;
		}
		pic[maxx]=0;
	}
	return 0;
}
