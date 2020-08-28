#可持久化Trie  
---
## 异或问题  
#### 一般的思维方式  

```
考虑按位计算，即将每一个数字拆成32位0/1。
```
#### 例题
##### [最长异或路径](https://www.luogu.org/problemnew/show/P4551)(bitwise trie)  

```cpp
#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+10;
struct ppp{
	int son[2];
}trie[MAX*32];
int n,head[MAX],nex[MAX<<1],to[MAX<<1],val[MAX<<1];
int XOR[MAX];
int tot,root=1;
int maxx=-1;
void add(int u,int v,int w)
{
	tot++;
	to[tot]=v;
	val[tot]=w;
	nex[tot]=head[u];
	head[u]=tot;
}
void dfs(int u,int deep,int fa)
{
	XOR[u]=deep;
	for(int i=head[u];i;i=nex[i])
		if(to[i]!=fa)
			dfs(to[i],XOR[u]^val[i],u);
}
void creat_trie(int x)
{
	x=XOR[x];
	int noww=root;
	for(int i=30;i>=0;i--)
	{
		int u=x&(1<<i);
		if(u!=0)	u=1;
		if(!trie[noww].son[u])
			trie[noww].son[u]=tot++;
		noww=trie[noww].son[u];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w);
		add(v,u,w);
	}
	dfs(1,0,0);
	tot=2;
	for(int i=1;i<=n;i++)
		creat_trie(i);
	for(int j=1;j<=n;j++)
	{
		int noww=root,ans=0,x=XOR[j];
		for(int i=30;i>=0;i--)
		{
			int k=x&(1<<i);
			if(k!=0)	k=1;
			k^=1;
			ans<<=1;
			if(trie[noww].son[k])
			{
				noww=trie[noww].son[k];
				ans|=1;
			}
			else
				noww=trie[noww].son[k^1];
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}
//4
//1 2 3
//2 3 4
//2 4 6
```
##### [异或序列](https://www.luogu.org/problemnew/show/P3917) (典型按位拆分)  
### 可持久化trie  
##### [最大异或和](https://www.luogu.org/problemnew/show/P4735)  

```cpp
// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
const int MAX=3e5+10;
const int MAXLEN=23;
int n,m,s[MAX<<1];
int trie[80*MAX][2],tot,root[MAX<<1],las[80*MAX];
void insert(int x,int jkl,int p,int q)
{
    if(jkl<0)
    {
        las[q]=x;
        return ;
    }
    int k=(s[x]>>jkl)&1;
    if(p)	trie[q][k^1]=trie[p][k^1];
    trie[q][k]=++tot;
    insert(x,jkl-1,trie[p][k],trie[q][k]);
    las[q]=max(las[trie[q][0]],las[trie[q][1]]);
}
int query(int l,int node,int x,int k)
{
    if(k<0)	return s[las[node]]^x;
    int c=(x>>k)&1;
    if(las[trie[node][c^1]]>=l)
        return query(l,trie[node][c^1],x,k-1);
    else
        return query(l,trie[node][c],x,k-1);
}
int main()
{
    scanf("%d%d",&n,&m);
    las[0]=-1;
    root[0]=++tot;
    insert(0,MAXLEN,0,root[0]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&s[i]);
        s[i]^=s[i-1];
        root[i]=++tot;
        insert(i,MAXLEN,root[i-1],root[i]);
    }
    for(int i=1;i<=m;i++)
    {
        char op[2];
        scanf("%s",op);
        if(op[0]=='A')
        {
            int jkl;
            scanf("%d",&jkl);
            n++;
            s[n]=jkl^s[n-1];
            root[n]=++tot;
            insert(n,MAXLEN,root[n-1],root[n]);
        }
        else
        {
            int l,r,x;
            scanf("%d%d%d",&l,&r,&x);
            printf("%d\n",query(l-1,root[r-1],x^s[n],23));
        }
    }
    return 0;
}
```
对于左边界r，记录las数组，表示以i节点为根的子树中的最大位置是多少，只有当las[i]>l-1时才走到这个子树中，由此平时trie的迭代建树就无法使用，改成递归建树，就像线段树一样合并信息，（也许这就是为什么lxl说主席树就是可持久化trie）