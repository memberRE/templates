#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int n, x, t;
    cin >> n >> x >> t;
    int tem = n % x!= 0;
    cout << t * (n / x + tem) << endl;
    return 0;
}