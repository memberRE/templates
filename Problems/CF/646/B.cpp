#include<iostream>
#include<algorithm>
#include <cstring>
using namespace std;
char s[1024];
int main()
{
    int t;
    scanf("%d\n", &t);
    while(t--)
    {
        scanf("%s", s);
        int len = strlen(s);
        int ans = 9999999;
        for (int i = 0; i < len;i++)
        {
            int tem = 0,tem1 = 0;
            for (int j = 0; j < len;j++)
            {
                if(j<i)
                {
                    if(s[j] == '0')
                        tem++;
                    else
                        tem1++;
                }
                else 
                {
                    if(s[j] == '1')
                        tem++;
                    else
                        tem1++;
                }
            }
            tem = min(tem, tem1);
            ans = min(tem, ans);
        }
        cout << ans << endl;
    }
    return 0;
}