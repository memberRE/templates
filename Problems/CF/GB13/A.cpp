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
const int MAX = 1e5 + 20;
int read()
{
    int x=0,flag=1; char c=getchar();
    while((c>'9' || c<'0') && c!='-') c=getchar();
    if(c=='-') flag=0,c=getchar();
    while(c<='9' && c>='0') {x=(x<<3)+(x<<1)+c-'0';c=getchar();}
    return flag?x:-x;
}
int pic[MAX];
int cnt[2];
int n,q;
int main() {
  n = read();
  q = read();
  for (int i = 1; i <= n; i++) {
    pic[i] = read();
    //123123123
    cnt[pic[i]]++;
  }
  for (int i = 1; i <= q; i++) {
    int op, x;
    op = read(), x = read();
    if (op == 1) {
      pic[x] ^= 1;
      cnt[pic[x] ^ 1]--;
      cnt[pic[x]]++;
    } else {
      if (cnt[1] >= x)
        printf("1\n");
      else
        printf("0\n");
    }
  }
  return 0;
}
