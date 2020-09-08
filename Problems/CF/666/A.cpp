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
const int MAX = 1e6 + 20;
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
ll pic[MAX], temm[MAX];
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++)
        scanf("%lld", &pic[i]);
    if (n == 1)
    {
        printf("1 1\n%lld\n1 1\n123\n1 1\n0\n", -(pic[1] + 123));
        return 0;
    }
    printf("1 %d\n", n - 1);
    for (int i = 1; i <= n - 1; i++)
        temm[i] = pic[i] % n;
    for (int i = 1; i <= n - 1; i++)
    {
        cout << (n - 1) * temm[i] << ' ';
        pic[i] += (n - 1) * temm[i];
    }
    cout << endl;
    ll jkl = -pic[n] % n;
    cout << 1 << " " << n << endl;
    for (int i = 1; i <= n - 1; i++)
        printf("%lld ", -pic[i]);
    cout << -(pic[n] + jkl) << endl;
    printf("%d %d\n%lld\n", n, n, jkl);
    return 0;
}