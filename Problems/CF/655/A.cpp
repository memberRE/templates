#include<iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n;i++)
            cout << 1 << ' ';
        cout << endl;
    }
    return 0;
}