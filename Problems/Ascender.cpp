#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	string s;
	int n,zero='0';
	cin>>n;
		cin>>s;
		zero='0';
		int num=0;
		int flag=1;
		for(int j=s.length()-1;j>=0;j--)
		{
			if(flag==0 and s[j]=='1')
			{
				printf("YES\n");
				flag=2;
				break;
			}
			if(s[j]==zero and flag==1)
				num++;
			if(num==7)
				flag=0;
		}
		if(flag!=2)
			printf("NO\n");
		return 0;
}
