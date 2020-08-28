#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stdio.h>
using namespace std;
typedef unsigned long long ull;
int main()
{
    int t;
    scanf("%d", &t);
    while(t--) 
    {
        ull x, k;
        cin >> x >> k;
        for (int i = 2; i <= k;i++)
        {
            ull tem = x;
            ull mmin = 9, mmax = 0;
            while (tem)
            {
                ull jkl = tem % 10;
                mmin = min(mmin, jkl);
                mmax = max(mmax, jkl);
                tem /= 10;
            }
            x += mmin * mmax;
            if(mmin == 0 || mmax == 0)
                break;
        }
        cout << x << endl;
    }
    return 0;
}