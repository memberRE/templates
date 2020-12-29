#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int AA[maxn],A[maxn],L[maxn],R[maxn],T[maxn],V[maxn];
int m, n;
map<int,int> h;

void GET_HASH()
{
    for(int i=1;i<=n;i++) AA[i]=A[i];
    sort(A+1,A+n+1);
    for(int i=1;i<=n;i++)
        if(A[i]!=A[i-1]) h[A[i]]=++m;
        else h[A[i]]=m;
    for(int i=1;i<=n;i++) A[i]=h[AA[i]];
}

bool cmp(int x,int y)
{
    if(x<y) return R[x]<L[y];
    else return L[x]<R[y];
}

void INIT()
{
    GET_HASH();
    for(int i=1;i<=m;i++) L[i]=n+1,R[i]=0;
    for(int i=1;i<=n;i++)
    {
        L[A[i]]=min(L[A[i]],i);
        R[A[i]]=max(R[A[i]],i);
    }
    for(int i=1;i<=m;i++) T[i]=i;
    sort(T+1,T+m+1,cmp);
}

int SOLVE()
{
    INIT();
    for(int i=1;i<=m;i++) V[T[i]]=V[T[i]-1]+1;
    int x=*max_element(V+1,V+m+1);
    return m-x;
}

int main()
{
    //freopen("A.in","r",stdin);
	cin>>n;
    for(int i=1;i<=n;i++)
	{
		cin>>A[i];
		//cout<<i<<endl;
	}
    cout<<SOLVE()<<endl;
	//fclose(stdin);
    return 0;
}

/*
11
1 1 2 5 3 4 2 1 5 5 2

3
*/
