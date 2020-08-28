#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef long long LL;
typedef vector<int> VI;

const LL MOD=998244353;
LL mypower(LL x,LL n)
{
    LL ans=1;
    while(n)
    {
        if(n&1) ans=ans*x%MOD;
        n>>=1;
        x=x*x%MOD;
    }
    return ans;
}

//k阶齐次线性递推数列
//把数列前面几项（编号从0开始，大概2k项，多点少点也可以）以vector形式调用linear_sequence的get(vector,int)
//即可算出第n项
//复杂度 k^2logn

namespace linear_sequence
{
    const int maxn=40005;
    LL res[maxn],base[maxn],_c[maxn],_md[maxn];
    VI Md;

    void multi(LL *a,LL *b,int k)
    {
        for(int i=0;i<(k<<1);i++) _c[i]=0;
        for(int i=0;i<k;i++) if(a[i]) for(int j=0;j<k;j++) _c[i+j]=(_c[i+j]+a[i]*b[j])%MOD;
        for(int i=k+k-1;i>=k;i--) if(_c[i]) for(int j=0;j<Md.size();j++) _c[i-k+Md[j]]=(_c[i-k+Md[j]]-_c[i]*_md[Md[j]])%MOD;
        for(int i=0;i<k;i++) a[i]=_c[i];
    }
    int solve(LL n,VI a,VI b)
    {
        LL ans=0,pnt=0;
        int k=a.size();
        //assert(a.size()==b.size());
        for(int i=0;i<k;i++) _md[k-1-i]=-a[i];
        _md[k]=1;
        Md.clear();
        for(int i=0;i<k;i++) if(_md[i]) Md.push_back(i);
        for(int i=0;i<k;i++) res[i]=base[i]=0;
        res[0]=1;
        while((1ll<<pnt)<=n) pnt++;
        for(int p=pnt;p>=0;p--)
        {
            multi(res,res,k);
            if((n>>p)&1)
            {
                for(int i=k-1;i>=0;i--) res[i+1]=res[i];
                res[0]=0;
                for(int j=0;j<Md.size();j++) res[Md[j]]=(res[Md[j]]-res[k]*_md[Md[j]])%MOD;
            }
        }
        for(int i=0;i<k;i++) ans=(ans+res[i]*b[i])%MOD;
        return (ans+MOD)%MOD;
    }
    VI BM(VI s)
    {
        VI C(1,1),B(1,1);
        int L=0,m=1,b=1;
        for(int n=0;n<s.size();n++)
        {
            LL d=0;
            for(int i=0;i<L+1;i++) d=(d+(LL)C[i]*s[n-i])%MOD;
            if(!d) ++m;
            else if((L<<1)<=n)
            {
                VI T=C;
                LL c=MOD-d*mypower(b,MOD-2)%MOD;
                while(C.size()<B.size()+m) C.push_back(0);
                for(int i=0;i<B.size();i++) C[i+m]=(C[i+m]+c*B[i])%MOD;
                L=n+1-L,B=T,b=d,m=1;
            }
            else
            {
                LL c=MOD-d*mypower(b,MOD-2)%MOD;
                while(C.size()<B.size()+m) C.push_back(0);
                for(int i=0;i<B.size();i++) C[i+m]=(C[i+m]+c*B[i])%MOD;
                ++m;
            }
        }
        return C;
    }
    int get(VI a,LL n)
    {
        VI c=BM(a);
        c.erase(c.begin());
        for(int i=0;i<c.size();i++) c[i]=(MOD-c[i])%MOD;
        return solve(n,c,VI(a.begin(),a.begin()+c.size()));
    }
}

int main()
{

	return 0;
}
