#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define mem(a) memset((a),0,sizeof((a)))
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5, MAXM = 1e7;
const int INF = 0x7fffffff;
ll a[MAXN];
int n, m;
ll val[MAXM],lasans;
int sz[MAXM], heap[MAXM], l[MAXM], r[MAXM];
int tot;

struct FHQ_Treap
{
    int root;

    inline void Update(int x)
    {
        sz[x] = sz[l[x]] + sz[r[x]] + 1;
        return;
    }

    inline int Merge(int x, int y)
    {
        if (!x || !y)
            return x + y;
        if (heap[x] < heap[y])
            return r[x] = Merge(r[x], y), Update(x), x;
        return l[y] = Merge(x, l[y]), Update(y), y;
    }

    inline void Split(int x, ll key, int &u, int &v)
    {
        if (!x)
        {
            u = v = 0;
            return;
        }

        if (val[x] <= key)
            u = x, Split(r[x], key, r[u], v);
        else
            v = x, Split(l[x], key, u, l[v]);

        Update(x);
        return;
    }

    inline int Create(ll key)
    {
        val[++tot] = key, heap[tot] = rand(), sz[tot] = 1;
        return tot;
    }

    int x, y, z;

    inline void Insert(ll key)
    {
        Split(root, key, x, y);
        root = Merge(x, Merge(Create(key), y));
        return;
    }

    inline void Delete(ll key)
    {
        Split(root, key, x, z);
        Split(x, key - 1, x, y);
        y = Merge(l[y], r[y]);
        root = Merge(x, Merge(y, z));
        return;
    }

    inline int FindRank(int key)
    {
        Split(root, key - 1, x, y);
        int ans = sz[x] + 1;
        root = Merge(x, y);

        return ans;
    }

    inline void Build(int l, int r)
    {
        for (int i = l; i <= r; i++)
            Insert(a[i]);
        return;
    }

    inline ll FindKey(int x, int rak)
    {
        if (rak <= sz[l[x]])
            return FindKey(l[x], rak);
        if (rak == sz[l[x]] + 1)
            return val[x];
        return FindKey(r[x], rak - sz[l[x]] - 1);
    }

    inline int Lower(int key)
    {
        Split(root, key - 1, x, y);

        int ans;
        if (sz[x])
            ans = FindKey(x, sz[x]);
        else
            ans = -INF;

        root = Merge(x, y);
        return ans;
    }

    inline ll Upper(ll key)
    {
        Split(root, key, x, y);

        ll ans;
        if (sz[y])
            ans = FindKey(y, 1);
        else
            ans = INF;
        
        root = Merge(x, y);
        return ans;
    }

} FT[MAXN << 2];

#define mid ((x + y) >> 1)
#define lson (pst << 1)
#define rson (pst << 1 | 1)
//#define lson (node<<1)
//#define rson ((node<<1)|1)
//#define mid ((l+r)>>1)

struct SegmentTree
{
    int root[MAXN << 2];

    inline void Build(int x, int y, int pst)
    {
        FT[pst].Build(x, y);
        if (x != y)
            Build(x, mid, lson), Build(mid + 1, y, rson);
        return;
    }

    inline int QueryRank(int x, int y, int pst, int l, int r, ll key)
    {
        if (y < l || x > r)
            return 0;
        if (l <= x && y <= r)
            return FT[pst].FindRank(key) - 1;

        return QueryRank(x, mid, lson, l, r, key) + QueryRank(mid + 1, y, rson, l, r, key);
    }

    inline int QueryKey(int l, int r, int rak)
    {
        ll x = 0, y = 10000000000000ll, ans = -1;//maybe error
        while (x <= y)
        {
            if (QueryRank(1, n, 1, l, r, mid) + 1 <= rak)
                ans = mid, x = mid + 1;
            else
                y = mid - 1;
        }

        return ans;
    }

    inline void Update(int x, int y, int pst, int p, ll k)
    {
        FT[pst].Delete(a[p]);
        FT[pst].Insert(k);
        if (x != y)
        {
            if (p <= mid)
                Update(x, mid, lson, p, k);
            else
                Update(mid + 1, y, rson, p, k);
        }
        return;
    }

    inline int Lower(int x, int y, int pst, int l, int r, int k)
    {
        if (y < l || x > r)
            return -INF;
        if (l <= x && y <= r)
            return FT[pst].Lower(k);
        return max(Lower(x, mid, lson, l, r, k), Lower(mid + 1, y, rson, l, r, k));
    }

    inline ll Upper(int x, int y, int pst, int l, int r, ll k)
    {
        if (y < l || x > r)
            return INF;
        if (l <= x && y <= r)
            return FT[pst].Upper(k);
        return min(Upper(x, mid, lson, l, r, k), Upper(mid + 1, y, rson, l, r, k));
    }

} ST;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
	    tot=0;
	    lasans=0;
	    memset(FT,0,sizeof(FT));
	    memset(ST.root,0,sizeof(ST.root));
	    mem(val);
	    mem(l);
	    mem(r);
	    mem(sz);
	    mem(heap);
	    //memset(heap,0,sizeof(heap));
		scanf("%d%d",&n,&m);
	    for(int i=1;i<=n;i++)
	        scanf("%lld",&a[i]);
	    ST.Build(1, n, 1);
	    for (int i = 1, opt; i <= m; i++)
	    {	
	        ll p;
			scanf("%d", &opt);
	        if(opt==1)
	        {
	        	scanf("%lld",&p);
	        	p^=lasans;
	            ST.Update(1,n,1,p,a[p]+10000000);
	            a[p]+=10000000;
			}
			else
			{
				ll r,k;
				scanf("%lld%lld",&r,&k);
				r^=lasans;
				k^=lasans;
				ll tem=ST.Upper(1, n, 1, 1, r, k-1);
				if(tem==(ll)INF or tem>k)
				{
					printf("%lld\n",k);
					lasans=k;
				}
				else
				{
					int rnk=ST.QueryRank(1, n, 1, 1, r, tem) + 1;
					int L=rnk;
					int R=r;
					while(L<R)
					{
						int MID=(L+R)>>1;
						ll jkl=ST.QueryKey(1, r, MID);
						if(jkl-k==rnk-MID)
							L=MID+1;
						else
							R=MID;
					}
					if(L>r)
					{
						lasans=ST.QueryKey(1,r,r)+1;
						printf("%lld\n",lasans);
					}
					else
					{
						lasans=ST.QueryKey(1,r,L-1)+1;
						printf("%lld\n",lasans);
					}
				}
			}
	    } 
	}
    return 0;
}
