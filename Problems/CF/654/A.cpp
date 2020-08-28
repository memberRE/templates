#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    int Y;
    cin >> Y;
    while(Y--)
    {
        int t;
        cin >> t;
        cout << ((t - 1) / 2) + 1<<endl;
    }
    return 0;
}