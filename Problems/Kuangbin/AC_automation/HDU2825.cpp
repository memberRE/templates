#include<iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
const int TYPE = 26;
const int MAX = 256;
const int MAXN = 64;
const int MOD = 20090717;
int n, m, k;
char temm[MAXN];
struct acam{
    int trie[MAX][TYPE],num[MAX],tot,fail[MAX];
    int dp[MAXN][MAX][1 << 11];
    void init()
    {
        memset(trie, 0, sizeof(trie));
        memset(num, 0, sizeof(num));
        tot = 0;
    }
    void readin(char * a,int id)
    {
        int k=strlen(a),now=0;
        for(int i=0;i<k;i++)
        {
            if(!trie[now][a[i]-'a'])
                trie[now][a[i]-'a']=++tot;
            now=trie[now][a[i]-'a'];
            //num[now] = 0;
        }
        num[now]=(1<<(id-1));
    }
    void getfail()
    {
        queue<int> q;
        fail[0] = 0;
        for(int i=0;i<TYPE;i++)
            if(trie[0][i])
                q.push(trie[0][i]), fail[trie[0][i]] = 0;
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
            num[k] |= num[fail[k]];
            for(int i=0;i<TYPE;i++)
                if(trie[k][i])
                {
                    fail[trie[k][i]]=trie[fail[k]][i];
                    q.push(trie[k][i]);
                }
                else 
                    trie[k][i]=trie[fail[k]][i];
        }
    }
    int mfs()
    {
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        for (int i = 0; i < n;i++)
            for (int j = 0; j <= tot;j++)
                for (int K = 0; K < (1 << m);K++)
                {
                    if(dp[i][j][K]>0)
                    {
                        for (int x = 0; x < TYPE;x++)
                        {
                            dp[i + 1][trie[j][x]][K | num[trie[j][x]]] += dp[i][j][K];
                            dp[i + 1][trie[j][x]][K | num[trie[j][x]]] %= MOD;
                        }
                    }
                }
        int ans = 0;
        for (int i = 0; i < (1 << m);i++)
        {
            int cnt = 0;
            int tem = i;
            while(tem)
                cnt++, tem -= tem & (-tem);
            if(cnt>=k)
            {
                for (int j = 0; j <= tot;j++)
                {
                    ans += dp[n][j][i];
                    ans %= MOD;
                }
            }
        }
        return ans;
    }
}ac;

int main()
{
    while(1)
    {
        scanf("%d%d%d", &n, &m, &k);
        if(n==0 and m==0 and k==0)
            return 0;
        ac.init();
        for (int i = 1; i <= m;i++)
        {
            scanf("%s", temm);
            ac.readin(temm, i);
        }
        ac.getfail();
        printf("%d\n", ac.mfs());
    }
    return 0;
}