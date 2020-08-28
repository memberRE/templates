#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef unsigned long long ull;
char c;
int main()
{
	
	ull ans=0;
	c=getchar();
	while(c!='\n')
	{
		if(c>='0' and c<='9')
		ans+=c-'0';
		c=getchar();
	} 
	while(ans>9)
	{
		ull lin1=ans,lin2=0;
		while(lin1)
		{
			lin2+=lin1%10;
			lin1/=10;
		}
		ans=lin2;
	}
	cout<<ans<<endl;
	return 0;
}

