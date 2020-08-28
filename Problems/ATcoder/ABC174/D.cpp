#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;
typedef long long  ll;
char s[200009];
int main()
{
    int n;
    cin >> n;
    scanf("%s", s+1);
    int ans = 0, l = 1, r = n;
    while (l<r)
    {
        while (s[l] == 'R')
            l++;
        while (s[r] == 'W')
            r--;
        if (l >= r)
            break;
        ans++;
        swap(s[l], s[r]);
    }
    cout << ans << endl;
    return 0;
}