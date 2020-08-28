#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;
int a[300];
int main()
{
	for(int i=1;i<=10000;i++)
	{
		int k=i^(i<<1)&255;
		if(k<256)
		a[k]=i;
	}
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int l;
		cin>>l;
		cout<<a[l]<<" ";
	}
	return 0;
 } 
