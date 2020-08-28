#include<bits/stdc++.h>
using namespace std;
int n,p;
int main()
{
	scanf("%d%d",&n,&p);
	int cnt=0;
	int P=p;
	while(P)
	{
		P/=10;
		cnt++;
	}
	if(cnt>n)
		printf("T_T");
	else
	{
		printf("%d",p);
		int jkl=n-cnt;
		while(jkl--)
			putchar('0');
	}
	return 0;
}
