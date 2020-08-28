#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define x first
#define y second
#define rep(i,a,b) for(int i=a;i<b;++i)
#define per(i,a,b) for(int i=a-1;i>=b;--i)
#define fuck(x) cout<<'['<<#x<<' '<<(x)<<']'
#define add(x,y) x=((x)+(y)>=mod)?(x)+(y)-mod:(x)+(y)
#define sub(x,y) x=((x)-(y)<0)?(x)-(y)+mod:(x)-(y)
#define eps 1e-10
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3fll;
const int MX = 1e5 + 5;
const int mod = 1e9 + 9;
 
 
vector<PII>v[MX];
vector<int>vx[MX], vid[MX];
vector<int>up[MX], d[MX];
bool vis[MX], can[MX];
priority_queue<int>q1;
priority_queue<int, vector<int>, greater<int> >q2;
bool check(vector<int>& u) {
    rep(i, 0, u.size()) if(d[u[i]].size() == 1) return 0;
    return 1;
}
void modify1(int x) {
    rep(i, 0, up[x].size()) {
        int y = up[x][i];
        d[y].erase(find(d[y].begin(), d[y].end(), x));
        if(!vis[y] && d[y].size() == 1) can[d[y][0]] = 0;
    }
}
void modify2(int x) {
    rep(i, 0, d[x].size()) {
        int y = d[x][i];
        up[y].erase(find(up[y].begin(), up[y].end(), x));
        if(!vis[y] && check(up[y])) q1.push(y), q2.push(y), can[y] = 1;
    }
}
int main() {
#ifdef local
    freopen("in.txt", "r", stdin);
#endif // local
 
    int n, x, y, id; cin >> n;
    rep(i, 0, n) {
        cin >> x >> y;
        v[y].push_back(PII(x, i));
    }
    rep(i, 0, n) if(!v[i].empty()) sort(v[i].begin(), v[i].end());
    rep(i, 0, n) rep(j, 0, v[i].size()) vx[i].push_back(v[i][j].x), vid[i].push_back(v[i][j].y);
    rep(i, 0, n) rep(j, 0, v[i].size()) {
        x = v[i][j].x, id = v[i][j].y;
        if(!vx[i + 1].empty()) {
            int l = lower_bound(vx[i + 1].begin(), vx[i + 1].end(), x - 1) - vx[i + 1].begin();
            int r = upper_bound(vx[i + 1].begin(), vx[i + 1].end(), x + 1) - vx[i + 1].begin();
            rep(k, l, r) up[id].push_back(vid[i + 1][k]);
            rep(k, l, r) d[vid[i + 1][k]].push_back(id);
        }
    }
    rep(i, 0, n) if(up[i].empty() || check(up[i])) q1.push(i), q2.push(i), can[i] = 1;
    ll ans = 0;
    rep(i, 0, n) {
        if(i % 2 == 0) {
            while(!q1.empty()) {
                x = q1.top(); q1.pop();
                if(vis[x] || !can[x]) continue;
                vis[x] = 1;
                ans = (ans * n + x) % mod;
                modify1(x);
                modify2(x);
                break;
            }
        } else {
            while(!q2.empty()) {
                x = q2.top(); q2.pop();
                if(vis[x] || !can[x]) continue;
                vis[x] = 1;
                ans = (ans * n + x) % mod;
                modify1(x);
                modify2(x);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
