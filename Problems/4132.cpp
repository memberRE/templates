#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cctype>

using namespace std;

int read()
{
    int x=0,f=1;char ch=getchar();
    while (!isdigit(ch)){if (ch=='-') f=-1;ch=getchar();}
    while (isdigit(ch)){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

char s[500050];

int t,k;

struct SuffixAutomaton
{
    int last=1,cnt=1;

    int len[1000050],trans[1000050][26],fa[1000050];

    int c[1000050],a[1000050],size[1000050],sum[1000050];

    void Insert(int c)
    {
        int p=last,np=++cnt;
        last=np;
        len[np]=len[p]+1;
        size[np]=1;
        for (;p && !trans[p][c];p=fa[p])
            trans[p][c]=np;
        if (!p)
            fa[np]=1;
        else
        {
            int q=trans[p][c];
            if (len[p]+1==len[q])
                fa[np]=q;
            else
            {
                int nq=++cnt;
                len[nq]=len[p]+1;
                memcpy(trans[nq],trans[q],sizeof(trans[q]));
                fa[nq]=fa[q];
                fa[q]=fa[np]=nq;
                for (;trans[p][c]==q;p=fa[p])
                    trans[p][c]=nq;
            }
        }
    }

    void Build()
    {
        int len=strlen(s+1);
        for (int i=1;i<=len;i++)
            Insert(s[i]-'a');
    }

    void Work()
    {
        for (int i=1;i<=cnt;i++)
            c[len[i]]++;
        for (int i=1;i<=cnt;i++)
            c[i]+=c[i-1];
        for (int i=1;i<=cnt;i++)
            a[c[len[i]]--]=i;
        for (int i=cnt;i;i--)
            if (t)
                size[fa[a[i]]]+=size[a[i]];
            else
                size[a[i]]=1;
        size[1]=0;
        for (int i=cnt;i;i--)
        {
            sum[a[i]]=size[a[i]];
            for (int j=0;j<26;j++)
                if (trans[a[i]][j])
                    sum[a[i]]+=sum[trans[a[i]][j]];
        }
    }

    void Solve()
    {
        if (k>sum[1])
        {
            puts("-1");
            return;
        }
        int now=1;
        k-=size[now];
        while (k>0)
        {
            int p=0;
            while (k>sum[trans[now][p]])
            {
                k-=sum[trans[now][p]];
                p++;
            }
            now=trans[now][p];
            putchar('a'+p);
            k-=size[now];
        }
        return;
    }

}SAM;

int main()
{
    scanf("%s%d%d",s+1,&t,&k);
    SAM.Build();
    SAM.Work();
    SAM.Solve();
    return 0;
}