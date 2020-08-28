#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef long long ll;
int main()
{
    int n, s;
    cin >> n >> s;
    int mean = s / n;
    int lef = s - mean * n + mean;
    if (mean > 1)
    {
        cout << "YES" << endl;
        for (int i = 1; i < n;i++)
            cout << mean << ' ';
        cout << lef << endl;
        cout << 1;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}