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
int main()
{
    int d, t, s;
    cin >> d >> t >> s;
    if (s*t >=d)
    {
        puts("Yes");
    }
    else
        puts("No");
}