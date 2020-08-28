#include<bits/stdc++.h>
using namespace std;
int qpower(int a,int b,int c)
{
	int ans=1;
	a%=c;
	while(b)
	{
		if(b&1)
			ans=(ans*a)%c;
		b=b>>1;
		a=(a*a)%c;
	}
	return ans;
}
int main()
{
	while(1)
	{
		int n,p;
		cin>>n>>p;
		cout<<qpower(n,p-2,p)<<endl;
	}
}
