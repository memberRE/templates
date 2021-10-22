#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
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
const int MAX = 102;
int pic[MAX];
int main() {
  int t = read();
  while (t--) {
    int n = read(), u = read(), v = read();
    int flag = 1;
    for (int i = 1; i <= n; i++) {
      pic[i] = read();
      if (i != 1) {
        if (pic[i] != pic[i - 1] and flag == 1)
          flag = 0;
        if (abs(pic[i] - pic[i - 1]) > 1)
          flag = -1;
      }
    }
    if (flag == -1)
      printf("0\n");
    else if (flag == 0)
      printf("%d\n", min(u, v));
    else
      printf("%d\n",min(v+v,v+u));
  }
  return 0;
}