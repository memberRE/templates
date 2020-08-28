#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include <stdlib.h>
#include<vector>
#include<queue>
#include<set>
#include<map>
using namespace std;
typedef long long ll;
const int MAX = 1e5 + 20;
map< ll, set<int> > mapp[MAX];
int head[MAX], to[MAX << 1], nex[MAX << 1],edge_endd[MAX<<1],tot;
int rd[MAX];
ll val[MAX << 1];
int fa[MAX];
ll fa_val[MAX];
ll sum_son[MAX],ori_ans;
int main_node[MAX];
int n,q;
void addedge(int u,int v,ll w)
{
    tot++;
    to[tot] = v;
    nex[tot] = head[u];
    head[u] = tot;
    edge_endd[tot] = u;
    val[tot] = w;
    rd[v]++;
}
inline void insttt(int u,int v,int v_val)
{
    if(mapp[u].count(v_val))
        mapp[u][v_val].insert(v);
    else
    {
        set<int> tem;
        tem.insert(v);
        mapp[u][v_val] = tem;
    }
}
inline void deleee(int fa_p,ll ori_val,int son_p)
{
    mapp[fa_p][ori_val].erase(son_p);
    if (mapp[fa_p][ori_val].size() == 0)
        mapp[fa_p].erase(ori_val);
}
void dfs(int u,int father,ll las_edge_val)
{
    fa[u] = father;
    
    for (int i = head[u]; i;i = nex[i])
    {
		int v = to[i];
        ll v_val = val[i];
        if (v == father)
            continue;
        fa_val[v] = v_val;
        if (sum_son[u] - v_val < 0)
            main_node[u] = v;
        sum_son[u] = abs(sum_son[u] - v_val);

        insttt(u, v, v_val);
        dfs(v, u,v_val);
    }
    if (las_edge_val >= sum_son[u])
        ori_ans += las_edge_val - sum_son[u];
}

int main()
{
    scanf("%d%d", &n,&q);
    for (int i = 1; i <= n - 1;i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        ll tem = w;
        addedge(u, v, tem);
        addedge(v, u, tem);
    }
    for (int i = 1; i <= n;i++)
    {
        if (rd[i] == 1)
        {
            dfs(i, 0, 0);
            break;
        }
    }
        
    printf("%lld\n", ori_ans);
    for (int i = 1; i <= q;i++)
    {
        int p, w;
        scanf("%d%d", &p, &w);
        int real_p = p * 2 - 1;
        int fa_p = edge_endd[real_p], son_p = to[real_p];
        ll ori_val = val[real_p];
        if (fa[son_p] != fa_p)
            swap(fa_p, son_p);
        //-------------------------------change son
        if (ori_val >= sum_son[son_p])
            ori_ans -= (ori_val - sum_son[son_p]);
        if ((ll)w >= sum_son[son_p])
            ori_ans += (ll)w - sum_son[son_p];
        //--------------------------------------change fa
        {
            ll det = (ll)w - ori_val;
            ll ori_son_som = sum_son[fa_p];
            if (main_node[fa_p] == son_p)
            {
                if (sum_son[fa_p] + det >= 0)
                {
                    sum_son[fa_p] += det;
                    deleee(fa_p, ori_val, son_p);
                    insttt(fa_p, son_p, w);
                }
                else
                {
                    sum_son[fa_p] += det;
                    sum_son[fa_p] = abs(sum_son[fa_p]);
                    deleee(fa_p, ori_val, son_p);
                    map<ll, set<int>>::iterator it = mapp[fa_p].end();
                    it--;
                    main_node[fa_p] = *(it->second.begin());
                    insttt(fa_p, son_p, w);
                }
            }
            else
            {
                sum_son[fa_p] += -det;
                deleee(fa_p, ori_val, son_p);
                insttt(fa_p, son_p, w);
            }
            fa_val[son_p] = w;
            if (fa_val[fa_p] >= ori_son_som)
                ori_ans -= (fa_val[fa_p] - ori_son_som);
            if (fa_val[fa_p] >= sum_son[fa_p])
                ori_ans += fa_val[fa_p] - sum_son[fa_p];
            printf("%lld\n", ori_ans);
            //sum_son[fa_p] = abs(sum_son[fa_p] - det);
        }
    }
    return 0;
}
