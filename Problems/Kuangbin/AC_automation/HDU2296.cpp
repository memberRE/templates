#include <crtdefs.h>
#include<iostream>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
const int TYPE = 26;
const int MAX = 2048;
const int MAXN = 16;
int n, m;
char temm[104][MAXN];
struct acam{
    int trie[MAX][TYPE],num[MAX],tot,fail[MAX];
    int dp[55][MAX];
    int cur;
    string path[55][MAX];
    void init()
    {
        memset(trie, 0, sizeof(trie));
        memset(num, 0, sizeof(num));
        tot = 0;
    }
    void readin(char * a,int val)
    {
        int k=strlen(a),now=0;
        for(int i=0;i<k;i++)
        {
            if(!trie[now][a[i]-'a'])
                trie[now][a[i]-'a']=++tot;
            now=trie[now][a[i]-'a'];
        }
        num[now]=val;
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
            num[k] += num[fail[k]];
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
    void mfs()
    {
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        path[0][0] = "";
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j <= tot;j++)
            {
                if(dp[i][j]!=-1)
                {
                    for (int k = 0; k < TYPE;k++)
                    {
                        if(dp[i][j] + num[trie[j][k]] > dp[i+1][trie[j][k]])
                        {
                            dp[i+1][trie[j][k]] = dp[i][j] + num[trie[j][k]];
                            path[i+1][trie[j][k]] = path[i][j]+(char)(k+'a');
                        }
                        else if(dp[i][j] + num[trie[j][k]] == dp[i+1][trie[j][k]])
                        {
                            string str = path[i][j];
                            str.push_back(k+'a');
                            if(str < path[i+1][trie[j][k]])  path[i+1][trie[j][k]] = str;
                        }
                    }
                }
            }
        }
        int ans = 0,row;
        string str;
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= tot; j++)
                if(ans < dp[i][j]){
                    ans = dp[i][j];
                    row = i;
                }
 
        if(ans == 0)    {
            printf("\n");
            return;
        }
        str = "";
        for(int j = 0; j <= tot; j++)
            if(dp[row][j] == ans && ( str > path[row][j] || str == "") )
                str = path[row][j];
        cout<<str<<endl;
    }
}ac;

int main()
{
    int t;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d%d", &n, &m);
        ac.init();
        for (int i = 1; i <= m;i++)
            scanf("%s", temm[i]);
        for (int i = 1; i <= m;i++)
        {
            int jkl;
            scanf("%d", &jkl);
            ac.readin(temm[i], jkl);
        }
        ac.getfail();
        ac.mfs();
    }
    return 0;
}