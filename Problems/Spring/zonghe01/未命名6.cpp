#include<iostream> 
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
using namespace std;
typedef long long ll;
const int MAXM = 1e5 + 10;
const ll MOD = 1e9 + 9;
struct ppp{
	int x;
	int y;
	ppp(int xx=0,int yy=0){x=xx,y=yy;}
	bool operator < (const ppp & a) const
    {
        if(x!=a.x)
			return x<a.x;
		else
			return y<a.y;
    }
}pic[MAXM];
bool vztd[MAXM];
int x[MAXM],y[MAXM],m;
ll ans[MAXM];
//map<pair<int, int>, int> MAP;
map<ppp,int> MAP;
bool judge(int a, int b)
{
	if (MAP[(ppp){a,b+1}])
	{
		if (MAP[(ppp){a-1,b}]==0 and MAP[(ppp){a+1,b}]==0)
			return 0;
	}
	if (MAP[(ppp){a+1,b+1}])
	{
		if (MAP[(ppp){a+1,b}]==0 and MAP[(ppp){a+2,b}]==0)
			return 0;
	}
	if (MAP[(ppp){a-1,b+1}])
	{
		if (MAP[(ppp){a-2,b}]==0 and MAP[(ppp){a-1,b}]==0)
			return 0;
	}
	return 1;
}
priority_queue<int> mx;
priority_queue<int, vector<int>, greater<int> > mn;
int main()
{
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&pic[i].x,&pic[i].y);
		//MAP[make_pair(x[i], y[i])]=i;
		x[i]=pic[i].x;
		y[i]=pic[i].y;
		MAP[pic[i]]=i;
	}
	for(int i=1;i<=m;i++)
		if (judge(x[i],y[i]))
		{
			mx.push(MAP[pic[i]]);
			mn.push(MAP[pic[i]]);
		}
	int a,b;
	for(int i=1;i<=m;i++)
	{
		if (i&1)
		{
			ans[i]=mx.top();
			mx.pop();
		}
		else
		{
			ans[i] = mn.top();
			mn.pop();
		}
		if (vztd[ans[i]])
		{
			i--;
			continue;
		}
		if (!judge(x[ans[i]], y[ans[i]]))
		{
			i--;
			continue;
		}
		vztd[ans[i]]=1;
		a=pic[ans[i]].x;
		b=pic[ans[i]].y;
		MAP.erase((ppp){a,b});
		if (MAP[(ppp){a-1,b-1}])
		{
			if (judge(a - 1, b - 1))
			{
				mx.push(MAP[(ppp){a-1,b-1}]);
				mn.push(MAP[(ppp){a-1,b-1}]);
			}
		}
		if (MAP[(ppp){a,b-1}])
		{
			if (judge(a, b - 1))
			{
				mx.push(MAP[(ppp){a,b-1}]);
				mn.push(MAP[(ppp){a,b-1}]);
			}
		}
		if (MAP[(ppp){a+1,b-1}])
		{
			if (judge(a + 1, b - 1))
			{
				mx.push(MAP[(ppp){a+1,b-1}]);
				mn.push(MAP[(ppp){a+1,b-1}]);
			}
		}
	}
	ll tmp=1;
	ll res=0;
	for (int i=m;i>=1;i--)
	{
		res+=(ans[i]-1)*tmp;
		res%=MOD;
		tmp*=m;
		tmp%=MOD;
	}
	printf("%lld",res);
	return 0;
}
