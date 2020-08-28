#include <algorithm>
#include <cstring>
#include <locale>
#include <queue>
#include <stdio.h>
#include <string.h>
#include <string>
#include "iostream"
#include "cstdio"
using namespace std;
const int MAX=1e5+200;
const int TYPE=129;
int ans[4];
struct acam
{
    int trie[MAX][TYPE],num[MAX],tot,fail[MAX];
    int temnum[MAX],cnt;
    void readin(char * a)
    {
        int noww=0;
        for(int i=0;a[i];i++)
        {
            if(!trie[noww][a[i]])
                trie[noww][a[i]]=++tot;
            noww=trie[noww][a[i]];
        }
        num[noww]=cnt++;
    }
    void getfail()
    {
        queue<int>  q;
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
    void find(char * s)
    {
        int ans_top=0,p=0;
        memset(temnum, 0, sizeof(temnum));
        for(int i=0;s[i];i++)
        {
            int ttt = s[i];
            temnum[p] = 1;
            p=trie[p][ttt];
            for(int j=p;j and !temnum[j];j=fail[j])
            {
                //ans+=temnum[j];
                if(num[j]>0)
                    ans[ans_top++]=num[j];
                if(ans_top>3)
                    printf("error");
                temnum[j]=1;
            }
        }
    }
}ac;
char S[MAX],tem[256];
int main()
{
    int n,m,total=0;
    ac.cnt=1;
    ac.tot = 0;
    scanf("%d\n",&n);
    for(int i=1;i<=n;i++)
    {
        gets(tem);
        ac.readin(tem);
    }
    ac.getfail();
    scanf("%d\n",&m);
    for(int i=1;i<=m;i++)
    {
        gets(S);
        ac.find(S);
        if(ans[0]+ans[1]+ans[2]==0)
            continue;
        total++;
        sort(ans,ans+3);
        printf("web %d:",i);
        for(int j=0;j<3;j++)
            if(ans[j]!=0)
                printf(" %d",ans[j]);
        printf("\n");
        ans[0]=ans[1]=ans[2]=0;
    }
    printf("total: %d",total);
    return 0;
}