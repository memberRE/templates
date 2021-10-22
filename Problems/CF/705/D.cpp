#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
const ll MOD = 1e9+7;
using namespace std;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
const int MAX = 2e5+20;
ll tree[MAX<<2]; // 每个点除了叶子都是gcd
ll las[MAX<<2]; // 除以gcd剩下的 // 后来发现不需要这个gcdlas // 后来发现还是需要 // tree[1]没有las
int pos[MAX]; // 在树种的位置
ll pic[MAX];
int n,q;

void build(int node, int l, int r)
{
    if (l == r)
        tree[node] = pic[l],pos[l] = node,las[node] = pic[l];
    else
    {
        int mid = (l + r) >> 1;
        build(ls, l, mid);
        build(rs, mid + 1, r);
        tree[node] = __gcd(tree[ls], tree[rs]);
        las[ls] /= tree[node];
        las[rs] /= tree[node];
        las[node] = tree[node];
    }
}
inline void change(int node,ll k){
    if (node == 1)
        return ;
    int neigh;
    int fa = node >> 1;
    if ( (node&1) == 1)
        neigh = node-1;
    else
        neigh = node+1;
    ll new_gcd = __gcd(k,las[neigh]);
    k /= new_gcd;
    las[neigh] /= new_gcd;
    las[node] *= k;
    tree[fa] = (tree[fa]*new_gcd)%MOD;
    change(fa,new_gcd);
    return ;
}
int main()
{
    n =read();
    q = read();
    for(int i = 1;i<=n;i++)
        pic[i] = read();
    if (n == 1)
    {
    	for(int i=1;i<=q;i++)
	    {
	        int x = read(),k = read();
	        pic[1]*=k;
			pic[1]%=MOD;
			printf("%lld\n",abs(pic[1]%MOD));
	    }
	    return 0;
	}
    build(1,1,n);
    for(int i=1;i<=q;i++)
    {
        int x = read(),k = read();
        change(pos[x],(ll)k);
        printf("%lld\n",abs(tree[1]%MOD));
    }
    return 0;
}
