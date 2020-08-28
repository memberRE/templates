#include<iostream>
#include <cstdio>
#include <algorithm>
#include<cmath>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int flag = 1;
        for (int i = 2; i <= sqrt(n);i++)
        {
            if((n/i)*i == n)
            {
                cout << n - (n / i)<<' '<<n/i<< endl;
                flag = 0;
                break;
            }
        }
        if(flag)
            cout << n - 1 <<' '<<1<< endl;
    }
    return 0;
}