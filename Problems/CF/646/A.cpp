#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n, x, ji = 0, ou = 0;
        cin >> n >> x;
        for (int i = 1; i <= n;i++)
        {
            int tem;
            cin >> tem;
            if (tem & 1)
                ji++;
            else
                ou++;
        }
        if(ji == 0)
        {
            cout << "No" << endl;
            continue;
        }
        ji--;
        x--;
        ji = (ji >> 1) << 1;
        if (x&1)
        {
            if (ou == 0)
            {
                cout << "No" << endl;
                continue;
            }
            ou--;
            x--;
            x -= ji;
            if (x<=0) 
            {
                cout << "Yes" << endl;
                continue;
            }
            else {
                x -= ou;
                if (x<=0) {
                    cout << "Yes" << endl;
                    continue;
                }
                cout << "No" << endl;
                continue;
            }
        }
        else 
        {
            x -= ji;
            if (x<=0) 
            {
                cout << "Yes" << endl;
                continue;
            }
            else {
                x -= ou;
                if (x<=0) {
                    cout << "Yes" << endl;
                    continue;
                }
                cout << "No" << endl;
                continue;
            }
        }
    }
    return 0;
}