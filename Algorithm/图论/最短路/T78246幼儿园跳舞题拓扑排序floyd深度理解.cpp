// luogu-judger-enable-o2
// Etavioxy
#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>
#include<cmath>
#define re register
#define ll long long
#define il inline
#define rep(i,s,t) for(re int i=(s);i<=(t);i++)
#define each(i,u) for(re int i=head[u];i;i=bow[i].nxt)
#define pt(ch) putchar(ch)
#define pti(x) printf("%d",x)
#define ptll(x) printf("%lld",x)
using namespace std;
//c_ints
il int ci(){
    re char ch;int f=1;
    while(!isdigit(ch=getchar()))ch=='-'? f=-1: 0;
    re int x=ch^'0';
    while(isdigit(ch=getchar()))x=(((x<<2)+x)<<1)+(ch^'0');
    return f*x;
}
enum{N=503};
class Edge{
public:
    int nxt,to,len;
    il void operator()(int a,int b,int c){
        nxt= a, to= b, len= c;
    }
}bow[N*N/2];
int head[N],n;
int dis[N][N],fa[N][N];
bool vis[N];
void dfs(int u){
    vis[u]= 1;
    int v,d;
    each(i,u){
        v= bow[i].to;
        if( !vis[v] ) dfs(v);
        d= bow[i].len;
        rep(i,1,n){
            if( dis[i][v]+d < dis[i][u] ){
                dis[i][u]= dis[i][v]+d;
                fa[i][u]= v;
            }
        }
    }
}
int u,v,s;
int f[N];
void dfs1(int u){
    vis[u]= 1;
    int v;
    each(i,u){
        v= bow[i].to;
        if( !vis[v] ) dfs1(v);
        if( f[v]+bow[i].len<f[u] ) f[u]= f[v]+bow[i].len;
    }
}
int main(){
    n= ci();
    int m= ci(), q= ci();
    for(int x,y,z,i=1;i<=m;i++){
        x= ci(), y= ci(), z= ci();
        bow[i](head[y],x,z);
        head[y]= i;
    }
    memset(dis,0x3f,sizeof(dis));
    rep(i,1,n) dis[i][i]= 0;
    rep(i,1,n) if(!vis[i]) dfs(i);
    re int x;
    bool in;
    int last= 0;
    while( q-- ){
        u= (ci()+last)%n+1, v= (ci()+last)%n+1, s= (ci()+last)%n+1;
        in= 0, x= v;
        if( dis[u][v]>0x3f3f3f00 || v==s || u==s ){
            pti( last=0 ), pt('\n');
            continue;
        }
        while( x!=u ){
            if( x==s ) in= 1;
            x= fa[u][x];
        }
        if( in ){
            memset(f,0x3f,sizeof(int)*(n+1));
            memset(vis,0,sizeof(bool)*(n+1));
            f[u]= 0;
            vis[s]= 1;
            dfs1(v);
            pti( last= ( f[v]>0x3f3f3f00 ? 0:f[v] ) );
        }
        else{
            pti( last= dis[u][v] );
        }
        pt('\n');
    }
    return 0;
}
