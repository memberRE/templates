#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 2e5 + 7;
char s1[MAX], s0[MAX];
int main() {
    int n;
    scanf("%d", &n);
    scanf("%s", s0 + 1);
    scanf("%s", s1 + 1);
    int ans = 0;
    s0[0] = s1[0] = 'G';
    for (int i = 1; i <= n;i++)
    {
        if(s0[i] != s1[i] && s0[i-1] == s1[i-1])
            ans++;
    }
    cout << ans;
    return 0;
}