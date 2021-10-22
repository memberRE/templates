#include <algorithm>
#include <cmath>
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
inline int get_1_num(unsigned int eax) {
  unsigned int edi = eax - ((eax >> 1) & 0x55555555);
    eax = edi & 0x33333333;
    edi = (edi >> 2) & 0x33333333;
    edi += eax;
    eax = ((edi >> 4) + edi) & 0x0f0f0f0f;
    eax = (eax * 0x01010101) >> 24;
    return eax;
}
int main() {
  int q = read();
  for (int i = 1; i <= q; i++) {
    int u = read(), v = read();
      int a[32]={0},b[32]={0};
      if (u > v) {
        printf("NO\n");
        continue;
      }
      int numu = get_1_num(u);
      int numv = get_1_num(v);
      if (numu < numv) {
        printf("NO\n");
        continue;
      }
      for(int j=0;j<30;j++)
      {
        if (u & (1 << j))
          a[j]=1;
        if (v & (1 << j))
          b[j]=1;
      }
      for (int j = 1; j <= 30; j++)
        a[j]+=a[j-1],b[j]+=b[j-1];
      int flag=1;
      for (int j = 0; j <= 30; j++)
        if (a[j] < b[j]) {
          flag = 0;
          break;
        }
      if (flag == 1)
        printf("YES\n");
      else
        printf("NO\n");
    }
  return 0;
}