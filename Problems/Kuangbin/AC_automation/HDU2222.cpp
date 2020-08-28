#include <crtdefs.h>
#include <cstring>
#include<iostream>
#include<cstdio>
#include<algorithm>
#include <queue>
#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX=1e6+200;
const int TYPE=26;
struct acam{
    int trie[MAX][TYPE],num[MAX],tot,fail[MAX];
    void init()
    {
        memset(trie, 0, sizeof(trie));
        tot=0;
        memset(num, 0, sizeof(num));
        memset(fail, 0, sizeof(fail));
    }
    void readin(char * a)
    {
        int k=strlen(a),now=0;
        for(int i=0;i<k;i++)
        {
            if(!trie[now][a[i]-'a'])
                trie[now][a[i]-'a']=++tot;
            now=trie[now][a[i]-'a'];
        }
        num[now]++;
    }
    void getfail()
    {
        queue<int> q;
        memset(fail,0,sizeof(fail));
        for(int i=0;i<TYPE;i++)
            if(trie[0][i])
                q.push(trie[0][i]);
        while(!q.empty())
        {
            int k=q.front();
            q.pop();
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
    int find(char * s)
    {
        int ans=0,p=0;
        for(int i=0;s[i];i++)
        {
            p=trie[p][s[i]-'a'];
            for(int j=p;j /*and ~num[j]*/;j=fail[j])
            {// don't know if is error
                ans+=num[j];
               // num[j]=-1;
            }
        }
        return ans;
    }
}ac;
char S[MAX],tem[256];
int main()
{
    int T;
    scanf("%d",&T);
    while (T--) 
    {
        int n;
        scanf("%d",&n);
        ac.init();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",tem);
            ac.readin(tem);
        }
        scanf("%s",S);
        ac.getfail();
        printf("%d\n",ac.find(S));
    }
    return 0;
}