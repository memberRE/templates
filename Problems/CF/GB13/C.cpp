#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int pic[5009];
int okk[5009];
int ones[5009]; //变成1后会被几次
int main() {
  int t = read();
  while (t--) {
    int n = read();
    ll ans = 0;
    for (int i = 1; i <= n; i++)
      okk[i] = pic[i] = read(), ones[i] = 0;
    for (int i = 2; i <= n; i++){
      int hpss = 0;
      for (int j = i - 1; j >= 1; j--) {
        int dis = i - j;
        if (dis == 1) {
          hpss += ones[j];
        } else
          hpss += dis <= pic[j] ?1:0;
      }
//      if (i == n-1)
//      	cout<< hpss<<" "<<ones[i-1]<<endl;
      if (pic[i] - hpss <= 0)
        okk[i] = 1, ones[i] = hpss - pic[i] + 1;
      else
        okk[i] = pic[i] - hpss;
      //cout<<okk[i]<<" ";
      ans += okk[i] - 1;
    }
    printf("%lld\n",ans+okk[1]-1);
  }
  return 0;
}
