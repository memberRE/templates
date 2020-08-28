#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int n,x,y;
	cin>>n>>x>>y;
	int k=n-(y/x);
	if(y%x!=0)
		k--;
	cout<<k;
	return 0;
}
