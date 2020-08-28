#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
const int maxn = 4e5+55;
ll a[maxn];
ll c[maxn];
ll d[maxn];
int main(){
    int n;
    ll sum=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    for(int i=0;i<n;++i){
        if(i>=2)c[i]=c[i-2]+a[i];
        else c[i]=a[i];
    }
    for(int i=n-1;i>=0;--i){
        if(i<=n-3)d[i]=d[i+2]+a[i];
        else d[i]=a[i];
    }
    ll maxx=c[0];
    for(int i=0;i<n;++i){
        maxx=max(maxx,c[i]+d[i+1]);
    }
    printf("%lld\n",maxx);
    return 0;
}