#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<string>
#include<stack>
using namespace std;
stack<long long> num;
string s;
int main()
{
	while(cin>>s/*scanf("%s",&s)!=EOF*/)
	{
		s.push_back('#');
		long long tem=0;
		bool flag=0;
		for(int i=0;i<s.length();i++)
		{
			if(s[i]>='0' and s[i]<='9')
			{
				tem*=10;
				tem+=(s[i]-'0');
			}
			else
			{
				num.push(tem);
				tem=0;
				if(flag)
				{
					long long k1=num.top();
					num.pop();
					long long k2=num.top();
					num.pop();
					num.push(k1*k2);
					flag=0;
				}
				if(s[i]=='*')
					flag=1;
			}
		}
		long long ans=0;
		while(!num.empty())
		{
			long long k=num.top();
			num.pop();
			k%=10000;
			ans+=k;
		}
		ans%=10000;
		printf("%lld\n",ans);
		s.clear();
	}
}
