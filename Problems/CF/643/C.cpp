#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
const int MAX = 1e6 + 20;
ll pic[MAX];
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    for (int i = a; i <= b;i++)
    {
        pic[i + b]++;
        pic[i + c + 1]--;
    }
    for (int i = 1; i < MAX; i++)
		pic[i] += pic[i - 1];
	for (int i = 1; i < MAX; i++)
		pic[i] += pic[i - 1];
    ll ans = 0;
    for (int i = c; i <= d;i++)
        ans += pic[MAX-1] - pic[i];
    cout << ans;
}