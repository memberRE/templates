#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX = 2e5 + 20;
int pic[MAX];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> pic[i];
    long long ans = 0;
    int maxx = pic[1];
    for (int i = 2; i <= n;i++)
    {
        if (pic[i] > maxx)
            maxx = pic[i];
        else
            ans += maxx - pic[i];
    }
    cout << ans << endl;
    return 0;
}