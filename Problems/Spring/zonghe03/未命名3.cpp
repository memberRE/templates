/*
* @Author: wxyww
* @Date:   2019-06-06 07:50:48
* @Last Modified time: 2019-06-06 07:56:06
*/
#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#include<ctime>
using namespace std;
typedef long long ll;
const int N = 300000 + 100;
ll read() {
    ll x=0,f=1;char c=getchar();
    while(c<'0'||c>'9') {
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9') {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}
ll a[N];
int main() {
    int n = read(),K = read();
    for(int i = 1;i <= n;++i) a[i] = read() + a[i - 1];
    ll ans = a[n] * K;
    sort(a + 1,a + n);
    for(int i = 1;i <= K - 1;++i)
	 ans -= a[i];
    cout<<ans;
    return 0;
}
