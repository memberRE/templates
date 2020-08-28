/*
* @Author: wxyww
* @Date:   2019-06-06 15:53:44
* @Last Modified time: 2019-06-06 16:36:31
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
int tree[N << 2];
int a[N];
void build(int rt,int l,int r) {
    if(l == r) {
        tree[rt] = a[l];return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1,l,mid);
    build(rt << 1 | 1,mid + 1,r);
    tree[rt] = max(tree[rt << 1],tree[rt << 1 | 1]);
}
int query(int rt,int l,int r,int L,int R) {
    if(L <= l && R >= r) return tree[rt];
    int mid = (l + r) >> 1;
    int ret = 0;
    if(L <= mid) ret = max(ret,query(rt << 1,l,mid,L,R));
    if(R > mid) ret = max(ret,query(rt << 1 | 1,mid + 1,r,L,R));
    return ret;
}
int nxt[N],pos[N],n;
int main() {
    n = read();
    for(int i = 1;i <= n;++i) a[i] = read(),pos[i] = n + 1;
    build(1,1,n);
    int ans = 0;
    nxt[n + 1] = n + 1;
    for(int i = n;i >= 1;--i) {
        nxt[i] = min(pos[a[i]],nxt[i + 1]);
        pos[a[i]] = i;
        for(int j = i;j < nxt[i];++j) {
            int x = query(1,1,n,i,j);
            if(i + x - 1 > j) j = i + x - 2;else ++ans;
        }
    }
    cout<<ans;
    return 0;
}
