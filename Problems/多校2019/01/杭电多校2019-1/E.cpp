#include <cstring>
#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include <queue>
#include <string.h>
using namespace std;
const int MAX = 1e4 + 200;
const long long INF = 0x7fffffffffffffff;
typedef long long ll;
struct ppp{
    int from, to, next;
    int flag;
    ll val;
} edge[2][MAX << 1];
int m, n;
int head[2][MAX], tot, s, t, vis;// remember to init tot
int dep[MAX], vztd[MAX], cur[MAX];  //for dinic
ll maxflow;
ll d[2][MAX];// for spfa
queue<int> que;
void addedge(int u,int v,ll w,int dir,int flag)
{
    //edge[dir][tot] = (ppp){u, v, w, head[dir][u], false};
    edge[dir][tot].from = u;
    edge[dir][tot].to = v;
    edge[dir][tot].val = w;
    edge[dir][tot].next = head[dir][u];
    head[dir][u] = tot;
    edge[dir][tot].flag = flag;
    tot++;
    // the spfa graph isn't the same with dinic graph
}
void spfa(int S,int T,int dir)
{
    memset(vztd, 0, sizeof(vztd));
    while(!que.empty())
        que.pop();
    vztd[0] = 1;
    vztd[S] = 1;
    que.push(S);
    d[dir][S] = 0;
    while(!que.empty()) 
    {
        int x = que.front();
        que.pop();
        vztd[x] = 0;
        for (int i = head[0][x]; i != -1; i = edge[0][i].next)
        {
            if(edge[0][i].flag != dir)
            	continue;
			if (d[dir][x] + edge[0][i].val < d[dir][edge[0][i].to])
            {
                d[dir][edge[0][i].to] = d[dir][x] + edge[0][i].val;
                if (!vztd[edge[0][i].to])
                {
                    vztd[edge[0][i].to] = 1;
                    que.push(edge[0][i].to);
                }
			}
        }
    }
}
bool bfs()
{
    for(int i=1;i<=n;i++)	
        cur[i]=head[1][i],dep[i]=0x3f3f3f3f,vztd[i]=0;
    dep[s]=0;
    while(!que.empty())
        que.pop();
    que.push(s);
    while(!que.empty())
    {
        int k=que.front();
        que.pop();
        vztd[k]=0;
        for(int i=head[1][k];i!=-1;i=edge[1][i].next)
        {
            int d=edge[1][i].to,lef=edge[1][i].val;
            if(dep[d]>dep[k]+1 and lef)
            {
                dep[d]=dep[k]+1;
                if(!vztd[d])
                {
                    que.push(d);
                    vztd[d]=1;
                }
            }
        }
    }
    if(dep[t]!=0x3f3f3f3f)	return 1;
    return 0;
}
ll dfs(int u,ll flow)
{
    if(u==t)	
    {
        vis = 1;
		maxflow+=flow;
        return flow;
    }
    ll used=0;
    for(int i=cur[u];i!=-1;i=edge[1][i].next)
    {
        cur[u]=i;
        int d=edge[1][i].to;
        ll lef=edge[1][i].val;
        if(lef and dep[d]==dep[u]+1)
        {
            ll low=dfs(d,min(flow-used,lef));
            if(low)
            {
                used+=low;
                edge[1][i].val-=low;
                edge[1][i^1].val+=low;
                if(used==flow)	break;
            }
        }
    }
    return used;
}
inline void init()
{
    memset(head, -1, sizeof(head));
    memset(d[0], 0x3f, sizeof(d[0]));
    memset(d[1], 0x3f, sizeof(d[1]));
    maxflow = 0;
    tot = 0;
    s = 1;
    t = n;
    vis = 0;
}
ll dinic()
{
    while(bfs())
    {
    	vis = 1;
    	while(vis == 1)
    	{
    		vis = 0;
			dfs(s, INF);
		}
		
	}
        
    return maxflow;
}
int main() {
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d", &n, &m);
        init();
        for (int i = 1; i <= m;i++)
        {
            int x, y;
            ll c;
            scanf("%d%d%lld", &x, &y, &c);
            addedge(x, y, c, 0,0);
            addedge(y, x, c, 0,1); 
        }
        spfa(1, n, 0);
        if(d[0][n] == 0x3f3f3f3f3f3f3f3f)
        {
            printf("0\n");
            continue;
        }
        spfa(n, 1, 1);
        int tem = tot;
        tot = 0;
        for (int i = 0; i < tem;i+=2)
        {
            if(d[0][edge[0][i].from] + edge[0][i].val + d[1][edge[0][i].to] == d[0][n])
            {
                addedge(edge[0][i].from, edge[0][i].to, edge[0][i].val, 1,0);
                addedge(edge[0][i].to, edge[0][i].from, 0, 1,0);
            }
        }
        printf("%lld\n", dinic());
    }
}
/*
2
3 4
1 2 1
2 3 1
1 3 2
1 3 3
9 16
1 5 4
1 4 5
1 2 1
2 4 7
2 3 6
3 4 9
5 4 1
6 5 4
7 5 3
7 4 2
8 4 9
6 7 5
8 7 7
9 6 4
9 7 5
8 9 9

*/
/*
ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
qv 1 2
qc 1 2

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
qas 1
ca 1 2
qnr 1

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
qps 
qc 1 2

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
ag 1
atg 1 1

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
ag 1
atg 1 1
atg 1 2
qgs 
qgps 1
qgrs 1

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
ag 1
atg 1 1
atg 1 2
qgvs 1
qgcs 1
qgam 1
qgav 1

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
qasu 0 101

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
qbs

ap 1 jack 1 100
ap 2 mark 1 100
ar 1 2 100
qmp 1 2
qsl 1 2
dfg 1 1

ap 1 jack 1 100
ap 2 mark 1 100
bf 1 1 1
qm 1

