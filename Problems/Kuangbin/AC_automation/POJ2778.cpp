#include<iostream>
#include<cstdio>
#include<algorithm>
#include <queue>
#include<cstring>
#define id(a) (a=='A'?0:a=='T'?1:a=='C'?2:3)
using namespace std;
typedef long long ll;
const ll MOD = 1e5;
const int MAX=128;
const int MAXN = 2e9 + 20;
const int TYPE=4;
int cnt;
char tem[16];
struct mat{
    ll m[102][102];
} A, e;
struct acam{
    int trie[MAX][TYPE],num[MAX],tot,fail[MAX];
    void readin(char * a)
    {
        int k=strlen(a),now=0;
        for(int i=0;i<k;i++)
        {
            if(!trie[now][id(a[i])])
                trie[now][id(a[i])]=++tot;
            now=trie[now][id(a[i])];
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
}ac;

mat mul(mat x,mat y,int jkl)
{
    mat c;
    for (int i = 0; i <= jkl;i++)
        for (int j = 0; j <= jkl;j++)
            c.m[i][j] = 0;
    for (int i = 0; i <= jkl;i++)
        for (int j = 0; j <= jkl;j++)
            for (int k = 0; k <= jkl;k++)
                c.m[i][j]=c.m[i][j]%MOD+x.m[i][k]*y.m[k][j]%MOD;
    return c;
}
mat quickpow(mat x,ll y)	//X^y
{
	mat ans=e;
	while(y)
	{
		if(y&1)
			ans=mul(ans,x,ac.tot);
		x=mul(x,x,ac.tot);
		y>>=1;
	}
	return ans;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for(int i=0;i<=100;i++)
        for(int j=0;j<=100;j++)
            e.m[i][j]=1;
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", tem);
        ac.readin(tem);
    }
    ac.getfail();
    mat gra_tra;
    memset(gra_tra.m,0,sizeof(gra_tra.m));
    for(int i=0;i<=ac.tot;i++)
    {
        if(ac.num[i]>0)
            continue;
        for(int j=0;j<=3;j++)
        {
            if(!ac.num[ac.trie[i][j]])
                A.m[i][ac.trie[i][j]]++;
        }
    }
    A=quickpow(A, m);
    ll ans=0;
    for(int i=0;i<=ac.tot;i++)
        ans=(A.m[0][i]+ans)%MOD;
    cout<<ans;
    return 0;
}
