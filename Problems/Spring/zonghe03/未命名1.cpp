#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int MAX=3e5+20;
typedef long long ll;
struct ppp{
	ll sum,pos;
	bool operator < (const ppp & a) const
    {
        return sum<a.sum;
    }
}SUM[MAX];
int k,n;
ll pic[MAX],ans;
int vztd[MAX];
priority_queue<ppp> que;
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=n;i>=1;i--)	// daoxu
		scanf("%lld",&pic[i]);
	for(int i=1;i<=n;i++)
	{
		SUM[i].sum=SUM[i-1].sum+pic[i];
		SUM[i].pos=i;
	//	que.push(SUM[i]);
	}
	ll lassum=0;
	int laspos=0,pushlast=0;
	for(int i=k;i>=1;i--)
	{
		ppp a;
		if(i==1)
		{
			ans+=(SUM[n].sum-lassum);
			break;
		}
		for(int j=pushlast+1;j<=n-i+1;j++)
		{
			que.push(SUM[j]);
			pushlast=j;
		}
		while(vztd[(que.top()).pos] or (que.top()).pos<=laspos)
			que.pop();
		a=que.top();
		que.pop();
		vztd[a.pos]=1;
		ans+=i*(a.sum-lassum);
		lassum=a.sum;
		laspos=a.pos;
	}
	cout<<ans;
	return 0;
}
