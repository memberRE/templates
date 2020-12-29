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
const int MAX = 1e3 + 20;
int dp[MAX][MAX];
int n;
int pic[MAX];
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
      cin >> pic[i];
    
}