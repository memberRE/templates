#include<iostream>
#include<map>
#include<cstring>
using namespace std;
int main()
{
	long long a,b;
	cin>>a>>b;
	if(a==-9223372036854775808 and b==-9223372036854775808)
	{
		cout<<"-18446744073709551616"<<endl;
		return 0;
	}
	if((a<=0 and b>=0) or (a>=0 and b<=0))
	{
		cout<<a+b<<endl;
		return 0;
	}
	else
	if(a<0 and b<0)
	{
		unsigned long long k=-a-b;
		cout<<'-'<<k<<endl;
		return 0;
	}
	else
	{
		unsigned long long k=a+b;
		cout<<k<<endl;
		return 0;
	}
	cout<<a+b<<endl;
	return 0;
}
