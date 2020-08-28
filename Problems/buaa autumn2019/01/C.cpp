#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+20;
struct ppp{
	int a,b,det;
}pic[MAX];
bool cam(ppp a,ppp b)
{
	return a.det<b.det;
}
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&pic[i].a);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&pic[i].b);
		pic[i].det=pic[i].a-pic[i].b;
	}
	sort(pic+1,pic+1+n,cam);
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		if(i<=k)
			ans+=pic[i].a;
		else
			ans+=min(pic[i].b,pic[i].a);
	}
	cout<<ans;
}
