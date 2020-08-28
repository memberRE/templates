#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
using namespace std;
long long two[]={1,2,4,8,16,32,64,128,256,512,1024,2048};
int main()
{
	string s;
	cin>>s;
	bool flag=0;
	long long k=s.length();
	for(long long i=0;i<k;i++)
	{
		if(s[i]>'1')
			s[i]='1',flag=1;
		if(flag)
			s[i]='1';
	}
	long long ans=0;
	for(long long i=0;i<k;i++)
		ans+=(s[i]-'0')*two[k-i-1];
	cout<<ans<<endl;
	return 0;
}
