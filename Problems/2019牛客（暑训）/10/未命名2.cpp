#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[512];
int main()
{
//	int t;
//	scanf("%d",&t);
//	while(t--)
//	{
//		
//	}
	f[1]=6;
	f[2]=7;
	for(int i=3;i<=60;i++)
	{
		f[i]=f[i-1]+f[i-2];
		printf("f[%d]=%lldll;\n",i,f[i]);
	}
	return 0;
}
