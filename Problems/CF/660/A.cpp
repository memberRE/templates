#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if (n > 30)
        {
            int tem = n - 30;
            if (tem == 10)
                cout << "Yes"<<endl<<"1 10 14 15" << endl;
            else if (tem == 6)
            {
                cout << "Yes"<<endl<<"5 6 10 15" << endl;
            }
            else if (tem == 14)
            {
                cout << "Yes"<<endl<<"6 7 10 21" << endl;
            }
            else
            {
                cout << "Yes" << endl;
                cout << 6 << " " << 10 << " " << 14 << ' ' << n - 30 << endl;
            }
        }
        else
            cout << "No" << endl;
    }
    return 0;
}