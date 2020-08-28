#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int p[5]={20011, 20021, 20023, 20029, 20047};
int a[6][102];
int aa[102];
int f[6][1000002];
int n,m,ansnum=0,pnum=5;
int mod(char* m,int b)//gao  mod
{
	long long d=0;
	bool biao=0;
	for(int i=0;i<strlen(m);i++) 
		{
			if(i==0 and m[i]=='-') {
				biao=1;
				continue; 
			}
			d=(d*10+(m[i]-'0'))%b;
		}
		if(biao) return -d;
		else return d;
}
void reak(int x)
{
  // scanf("\n");
    bool F = true;
    char c = getchar();
    for(; !isdigit(c); c = getchar()) if(c == '-') F = false;
    int d[pnum];
    for(int i = 0; i < pnum; i++) d[i] = 0;
    for(; isdigit(c); c = getchar())
        for(int i = 0; i < pnum; i++)
            d[i] = (d[i] * 10 + c - '0') % p[i];//-----��ħ--- 
    for(int i = 0; i < pnum; i++)
        a[i][x] = F ? d[i] : p[i] - d[i];
}
long long qing(int y,int x)
{
	long long ans=0;
	for(int i=n;i;i--)
		ans=(ans+a[y][i])*x%p[y];
	ans+=a[y][0];
	ans%=p[y];
	return ans;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++)	
		reak(i);
	for(int i=0;i<pnum;i++)
		for(int j=0;j<p[i];j++)
			f[i][j]=qing(i,j);	
	for(int i=0;i<=m;i++)
		{
			bool t = true;
        	for(int j = 0; j < pnum; j++)
            	if(f[j][i % p[j]]) t = false;
        	if(t) aa[ansnum++] = i;
		}
	cout<<ansnum<<endl;
	for(int i=0;i<ansnum;i++)
		printf("%d\n",aa[i]);
//	for(int i=0;i<=n;i++)
//		cout<<f[0][i]<<" ";
	return 0;
}