#include <algorithm>
#include<iostream>
#include <cstdio>
#include <string.h>
using namespace std;
const int TYPE = 26;
const int MAX = 1e6 + 20;
struct state{
    int len, link,end;
    int next[TYPE];
    state(){
        memset(next, 0, sizeof(next));
        len = link = end = 0;
    }
} sam[MAX << 1];
struct EDGE{
    int next, to;
} edge[MAX << 1];
int head[MAX << 1], cnt = 0;
int tot = 1, las = 1;// use 1 as root ,not like ac_automaton
char s[MAX];
int ans;
void add(int c)
{
    int cur = ++tot;
    sam[cur].end = 1;
    sam[cur].len = sam[las].len + 1;
    int p = las;
    las = cur;
    while(p and !sam[p].next[c])
    {
        sam[p].next[c] = cur;
        p = sam[p].link;
    }
    if(!p)
        sam[cur].link = 1;
    else
    {
        int q = sam[p].next[c];
        if (sam[q].len == sam[p].len + 1)
            sam[cur].link = q;
        else
        {
            int tem = ++tot;
            sam[tem] = sam[q];
            sam[tem].end = 0;
            sam[tem].len = sam[p].len + 1;
            while(p and sam[p].next[c]==q)
            {
                sam[p].next[c] = tem;
                p = sam[p].link;
            }
            sam[q].link = sam[cur].link = tem;
        }
    }
}
void addedge(int a,int b)
{
    ++cnt;
    edge[cnt].to = b;
    edge[cnt].next = head[a];
    head[a] = cnt;
}
void dfs(int u)
{
    for (int i = head[u]; i;i=edge[i].next)
    {
        dfs(edge[i].to);
        sam[u].end += sam[edge[i].to].end;
    }
    if(sam[u].end!=1)
        ans = max(ans, sam[u].end * sam[u].len);
}

int main()
{
    scanf("%s", s);
    for (int i = 0; s[i];i++)
        add(s[i] - 'a');
    for (int i = 2; i <= tot;i++)
        addedge(sam[i].link, i);
    dfs(1); //dfs(root);
    cout << ans;
    return 0;
}