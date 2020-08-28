#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;
const int MAX =1000009;
bool prime[1005000];
void isprime()
{
	prime[2]=1;
	for(int i=3;i<MAX;i++)
		prime[i]=i%2==0?0:1;
	int t=(int)sqrt(MAX*1.0);
	for(int i=3;i<t;i++)
		if(prime[i])
			for(int j=i*i;j<MAX;j+=(i<<1))
				prime[j]=0;
}
int main()
{
	isprime();
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(prime[k])
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
