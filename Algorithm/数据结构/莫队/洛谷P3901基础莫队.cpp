#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <cmath>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
const int MAX = 1e5 + 20;
using namespace std;
int read()
{
    int x = 0, flag = 1;
    char c = getchar();
    while ((c > '9' || c < '0') && c != '-')
        c = getchar();
    if (c == '-')
        flag = 0, c = getchar();
    while (c <= '9' && c >= '0')
    {
        x = (x << 3) + (x << 1) + c - '0';
        c = getchar();
    }
    return flag ? x : -x;
}
struct Query
{
    int blockId;
    int l, r;
    int rank;
} que[MAX];
bool cam(Query A, Query B) {
  return A.blockId == B.blockId ? A.r < B.r : A.blockId < B.blockId;
}
bool camParity(Query A, Query B) {      //奇偶性优化的比较函数
  return A.blockId != B.blockId?A.blockId < B.blockId:(A.blockId&1)?A.r<B.r:A.r>B.r;
}
int N, Q;
int pic[MAX];
int cnt[MAX], if_mult;
int ans[MAX];
int blockSize;
inline void add(int x) {
  cnt[pic[x]]++;
  if (cnt[pic[x]] == 2)
    if_mult++;
}
inline void del(int x) {
  cnt[pic[x]]--;
  if (cnt[pic[x]] == 1)
    if_mult--;
}
int main()
{
    N = read();
    Q = read();
    blockSize = N / sqrt((Q << 1) / 3);//实测这个最快
    for (int i = 1; i <= N;i++)
        pic[i] = read();
    for (int i = 1; i <= Q;i++)
    {
        que[i].l = read(),que[i].r = read();
        que[i].blockId = que[i].l / blockSize;
        que[i].rank = i;
    }
    sort(que + 1, que + 1 + Q, camParity);
    int L = 1, R = 0;
    for (int i = 1; i <= Q; i++) {
        int l = que[i].l,r = que[i].r;
        while (L < l)
          del(L++);
        while (L > l)
          add(--L);
        while (R > r)
          del(R--);
        while (R < r)
          add(++R);
        ans[que[i].rank] = if_mult;
    }
    for (int i = 1; i <= Q; i++)
      if (ans[i] != 0)
        printf("No\n");
      else
        printf("Yes\n");
    return 0;
}