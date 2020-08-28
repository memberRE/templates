#include<bits/stdc++.h>
using namespace std;
int main()
{
	char s[32];
	int k,ans=0,tem=0;
	scanf("%s %d",s,&k);
	for(int i=strlen(s)-1;i>=0;i--)
	{
		if(s[i]=='0')
			tem++;
		else
			ans++;
		if(k==tem)
			break;
		if(i==0)
			ans=strlen(s)-1;
	}
	cout<<ans;
}
