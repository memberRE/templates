#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stdio.h>
using namespace std;
int pic[128];
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++)
            cin >> pic[i];
        sort(pic + 1, pic + 1 + n);
        int flag = 0;
        for (int i = 2; i <= n;i++)
            if (pic[i] - pic[i-1] > 1)
                flag = 1;
        if (flag)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}