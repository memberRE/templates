#include <bits/stdc++.h>
 
using namespace std;
typedef long long LL;
const int MAXN = 1300000;
struct Edge {
    int to, next;
} edge[MAXN * 2];
int head[MAXN], tot;
int top[MAXN];//top[v] 表示v所在的重链的顶端节点
int fa[MAXN];//父亲节点
int deep[MAXN];//深度
int num[MAXN];//num[v] 表示以v为根的子树的[最大深度]
int p[MAXN];//p[v]表示v对应的位置
int fp[MAXN];//fp和p数组相反
int son[MAXN];//重儿子
int pos;
 
void init(int n) {
    tot = 0;
    memset(head, -1, (n+2) * sizeof(int));
    pos = 1;//使用树状数组，编号从头1开始
    memset(son, -1, (n+2) * sizeof(int));
}
 
void addedge(int u, int v) {
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
 
void dfs1(int u, int pre, int d) {
    deep[u] = d;
    fa[u] = pre;
    num[u] = 1;
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v != pre) {
            dfs1(v, u, d + 1);
            num[u] = max(num[v]+1, num[u]);
            if (son[u] == -1 || num[v] > num[son[u]]);
            son[u] = v;
        }
    }
}
 
void getpos(int u, int sp) {
    top[u] = sp;
    p[u] = pos++;
    fp[p[u]] = u;
    if (son[u] == -1) return;
    getpos(son[u], sp);
    for (int i = head[u]; i != -1; i = edge[i].next) {
        int v = edge[i].to;
        if (v != son[u] && v != fa[u]) getpos(v, v);
    }
}
 
 
 
int main() {
    int n = 0;
    while (scanf("%d", &n) != EOF) {
        init(n);
        for (int i = 1; i < n; ++i) {
            int f = 0;
            scanf("%d", &f);
            addedge(f, i+1);
        }
        dfs1(1, 0, 0);
        getpos(1,1);
        unordered_set<int> st;
        priority_queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if(!st.count(top[i])){
                q.push(num[top[i]]);
                st.insert(top[i]);
            }
        }
        LL ans = 0;
 
        int t = q.top();
        q.pop();
        q.push(t - 1);
 
        while(!q.empty()){
            int i = q.top();
            ans += q.top();
            q.pop();
 
            i--;
            if(i/2)q.push(i/2);
            if(i-i/2)q.push(i-i/2);
        }
        cout<<ans<<endl;
    }
}