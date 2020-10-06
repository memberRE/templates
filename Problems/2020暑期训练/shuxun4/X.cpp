#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <stdint.h>
#include<set>
#include<map>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
const int MAX = 1e6 + 20;
map<ll,int> mapp;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
struct EDGE{
    int x, y, w;
};
struct ppp{
    int val, node1, node2;
};
struct nodeAns
{
    int node, val;
    bool operator < (const nodeAns a) const {
        return val < a.val;
    }
};
int head[MAX], nex[MAX << 1], to[MAX << 1],wei[MAX<<1],tot = 1; // 2,3开始
EDGE edge[MAX];
int n, m, k;
vector<ppp> que;
vector<nodeAns> node[2][MAX];// 0 begin ,1 end
inline void addedge(int x,int y,int w)
{
    tot++;
    to[tot] = y;
    wei[tot] = w;
    nex[tot] = head[x];
    head[x] = tot;
}
inline void add(int type,int node1,int node2,int w)
{
    //if(node[type][node2].size() < 3)
    node[type][node2].push_back({node1, w});
    if(node[type][node2].size() > 3)
    {
        sort(node[type][node2].begin(), node[type][node2].end());
        node[type][node2].pop_back();
    }
}
int main()
{
    n = read(), m = read(), k = read();
    if (k > n or k > m)
    {
        printf("-1\n");
        return 0;
    }
    for (int i = 1; i <= m;i++)
    {
        int x = read(), y = read(), w = read();
        if (x == y)
            continue;
        if (x < y)
        	swap(x,y);
        ll hash = (ll)x*10000000+y;
        if (mapp.count(hash))
        	mapp[hash] = min(mapp[hash],w);
        else
        	mapp[hash] = w;
//        addedge(x, y, w);
//        addedge(y, x, w);
//        edge[i] = {x, y, w};
    }
    m = mapp.size();
    int temedgee = 1;
    for(auto edgg : mapp)
    {
    	ll x = edgg.first/10000000;
    	ll y = edgg.first%10000000;
    	int w = edgg.second;
    	addedge(x, y, w);
        addedge(y, x, w);
        edge[temedgee] = {(int)x, (int)y, w};
        temedgee++;
    }
    temedgee = 1;
    //  k < 5
    while(k < 5)
    {
        addedge(n + temedgee - 1, n + temedgee, 0);
        addedge(n + temedgee, n + temedgee - 1, 0);
        edge[m + temedgee] = {n + temedgee - 1, n + temedgee, 0};
        k++;
        temedgee++;
    }
	n += temedgee - 1;
	m += temedgee - 1;
    for (int i = head[1]; i;i = nex[i])
    {
        int v = to[i],w = wei[i];
        if (v == 1 || v == n)
            continue;
        que.push_back({w, v, 0});
    }
    for(ppp tem : que)
    {
        int temw = tem.val;
        int temnode = tem.node1;
        for (int i = head[temnode]; i;i = nex[i])
        {
            int v = to[i], w = wei[i];
            if (v == n || v == temnode || v == 1)
                continue;
            add(0,temnode, v, temw + w);
        }
    }
    que.clear();

    for (int i = head[n]; i;i = nex[i])
    {
        int v = to[i],w = wei[i];
        if (v == 1 || v == n)
            continue;
        que.push_back({w, v, 0});
    }
    for(ppp tem : que)
    {
        int temw = tem.val;
        int temnode = tem.node1;
        for (int i = head[temnode]; i;i = nex[i])
        {
            int v = to[i], w = wei[i];
            if (v == n || v == temnode || v == 1)
                continue;
            add(1,temnode, v, temw + w);
        }
    }

    int ans = INT32_MAX;

    for (int i = 1; i <= m;i++)
    {
        int temans = INT32_MAX;
        int x = edge[i].x,y = edge[i].y;
        for(nodeAns xNode : node[0][x])
            for(nodeAns yNode : node[1][y])
            {
                //set<int> pc = {xNode.node, yNode.node, x, y,1,n};
                if (xNode.node == yNode.node || xNode.node == y || yNode.node == x)
                //if (pc.size()!= 6)
                    continue;
                temans = min(temans, xNode.val + yNode.val + edge[i].w);
            }
        for(nodeAns xNode : node[1][x])
            for(nodeAns yNode : node[0][y])
            {
                //set<int> pc = {xNode.node, yNode.node, x, y,1,n};
                if (xNode.node == yNode.node || xNode.node == y || yNode.node == x)
                //if (pc.size()!= 6)
                    continue;
                temans = min(temans, xNode.val + yNode.val + edge[i].w);
            }
        ans = min(ans, temans);
    }
    if (ans == INT32_MAX)
        printf("-1\n");
    else
        printf("%d\n", ans);
    return 0;
}

