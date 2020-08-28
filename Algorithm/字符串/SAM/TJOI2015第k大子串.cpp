#include <algorithm>
#include<iostream>
#include <cstdio>
#include <stdio.h>
#include <string.h>
using namespace std;
const int TYPE = 26;
const int MAX = 5e5 + 20;
struct state{
    int len, link,end;
    int next[TYPE];
    state(){
        memset(next, 0, sizeof(next));
        len = link = end = 0;
    }
} sam[MAX << 1];
int tot = 1, las = 1;// use 1 as root ,not like ac_automaton
int dp[MAX << 1];
int rankk[MAX << 1], temrank[MAX]; // no neet to open MAX<<1;
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
void solve(int u,int k,int t)
{
    k -= sam[u].end;
    while(k>0)
    {
        int jkl = 0;
        while(k>dp[sam[u].next[jkl]])
        {
            k -= dp[sam[u].next[jkl]];
            jkl++;
        }
        u = sam[u].next[jkl];
        k -= sam[u].end;
        putchar(jkl + 'a');
    }
}
void getendd(int t)
{
    for (int i = 1; i <= tot;i++)
        temrank[sam[i].len]++;
    for (int i = 1; i <= tot;i++)
        temrank[i] += temrank[i - 1];
    for (int i = 1; i <= tot;i++)
        rankk[temrank[sam[i].len]--] = i;
    for (int i = tot; i;i--)
        if(t)
            sam[sam[rankk[i]].link].end += sam[rankk[i]].end;
        else
            sam[rankk[i]].end = 1;
    sam[1].end = 0;
}
int main()
{
    scanf("%s", s);
    int t, k;
    scanf("%d%d", &t, &k);
    for (int i = 0; s[i];i++)
        add(s[i] - 'a');
    getendd(t);
    for (int i = tot; i;i--)
    {
        dp[rankk[i]] = sam[rankk[i]].end;
        for (int j = 0; j < TYPE;j++)
            if(sam[rankk[i]].next[j])
                dp[rankk[i]] += dp[sam[rankk[i]].next[j]];
    }
    if (dp[1] < k)
        cout << -1;
     else
        solve(1, k, t);
    return 0;
}
