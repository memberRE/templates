#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[512];
int stk[512];
char T[512] = "abacaba\0";
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cin >> s;
        //cout << s << "%%$%$%$%$%" << endl;
        int ans[2] = {0,0};
        int top = 0;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            int flag = 0;
            for (; T[j];j++)
            {
                if(T[j] == s[i+j])
                    continue;
                if(s[i+j] == '?')
                    flag = 1;
                else
                    break;
            }
            if(T[j] == '\0')
            {
                ans[flag]++;
                if(flag == 1)
                    stk[top++] = i;
            }
                
        }
        if(ans[0]  > 1)
        {
            cout << "No" << endl;
        }
        else if(ans[0] == 1)
        {
            cout << "Yes" << endl;
            for (int i = 0; i < n;i++)
                cout << ((s[i] == '?') ? 'z' : s[i]);
            cout << endl;
        }
        else
        {
            if(ans[1] == 0)
            {
                cout << "No" << endl;
                continue;
            }
            int tem = -1;
            for (int i = 0; i < top;i++)
            {
                int flagg = 1;
                for (int j = stk[i] + 1; j <= stk[i] + 7;j++)
                {
                    int k = j;
                    for (; T[k - j];k++)
                    {
                        if(T[k-j] != s[k])
                        {
                            if(T[k-j] != T[k-i])
                                break;
                        }
                    }
                    if(!T[k-j])
                    {
                        flagg = 0;
                        break;
                    }
                }
                if(flagg)
                {
                    tem = stk[i];
                    break;
                }
            }
            if(tem == -1)
            {
                cout << "No" << endl;
                continue;
            }
            cout << "Yes" << endl;
            for (int i = tem; i < n && T[i - tem];i++)
                if(s[i] == '?')
                    s[i] = T[i - tem];
            for (int i = 0; i < n;i++)
                cout << ((s[i] == '?') ? 'z' : s[i]);
            cout << endl;
        }
    }
    return 0;
}