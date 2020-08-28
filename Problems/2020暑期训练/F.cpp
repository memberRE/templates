#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for (int i=a;i<=b;++i)

int fm[20005],a[11],A,id,mod,n;
queue<int> Q;

void output(int k,int dep)
{
	if (!~fm[k])
	{
		printf("%d\n",dep);
		return;
	}
	if (a[fm[k]]<=k)
	{
		output(k-a[fm[k]],dep+2);
		printf("1 %d\n3 %d %d\n",fm[k],fm[k],id);
	}
	else
	{
		output(k-a[fm[k]]+mod,dep+4);
		printf("1 %d\n3 %d %d\n2 %d\n3 %d %d\n",fm[k],fm[k],id,id,fm[k],id);
	}
}

inline void solve()
{
	if (A==mod)
	{
		printf("1\n1 %d\n",id);
		return;
	}
	fm[0]=-1;
	Q.push(0);
	while(!Q.empty())
	{
		int h=Q.front();
		Q.pop();
		For(i,1,n) if (!fm[(h+a[i])%mod])
		{
			fm[(h+a[i])%mod]=i;
			Q.push((h+a[i])%mod);
		}
	}
	if (!fm[A])
	{
		puts("-1");
		return;
	}
	output(A,0);
}

int main()
{
	scanf("%d%d",&n,&A);
	For(i,1,n)
	{
		scanf("%d",a+i);
		if (mod<a[i]) mod=a[i],id=i;
	}
	solve();
}
