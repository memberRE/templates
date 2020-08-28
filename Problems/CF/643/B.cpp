#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
const int MAX = 2e5 + 100;
int pic[MAX];
int n;
int main() {
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
            scanf("%d", &pic[i]);
        sort(pic + 1, pic + 1 + n);
        int ans = 0;
        int tem = 0;
        for (int i = 1; i <= n;i++)
        {
            tem++;
            if (pic[i] == tem)
            {
                ans++;
                tem = 0;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}