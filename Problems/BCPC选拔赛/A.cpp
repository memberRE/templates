#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 128;
int picx[MAX],picy[MAX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        picx[i] = x;
        picy[i] = y;
    }
    long long ans = -1;
    for (int i = 1; i <= n; i++) {
        int x = picx[i], y = picy[i];
        int maxx = 0;
        int maxy = 0;
        for (int j = 1; j <= n;j++) {
            if (picx[j] == x) {
                maxx = max(maxx, abs(picy[j] - y));
            }
            if (picy[j] == y) {
                maxy = max(maxy, abs(picx[j] - x));
            }
        }
        ans = max((long long)maxx * (long long)maxy, ans);
    }
    cout << ans;
}