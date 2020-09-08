#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
class TapeMeasure
{
public:
    vector<string> draw(int leftMark, int rightMark)
    {
        string one, two, three, forr, five;
        for (int i = 1; i <= (rightMark - leftMark) * 2 + 1; i++)
            one.append("#");
        for (int i = 1; i <= (rightMark - leftMark); i++)
            two.append("# ");
        two.append("#");
        int flag = 0, flag2 = 0;
        for (int i = leftMark; i <= rightMark; i += 5)
        {
            if (i % 5 != 0)
            {
                while (i % 5 != 0)
                    i++;
                i -= 5;
                continue;
            }
            if (flag == 0)
                flag = 1;
            else
                three.append(" ");
            three.append("#");
            if (i % 10 == 0)
            {
                if (flag2 == 0)
                    flag2 = 1;
                else
                    forr.append(" "),five.append(" ");
                forr.append("#");
                int tem = i;
                string temm;
                stack<char> stk;
                while(tem)
                {
                    stk.push(tem % 10 + '0');
                    tem /= 10;
                }
                while(!stk.empty())
                {
                    temm.push_back(stk.top());
                    stk.pop();
                }
                five.append(temm);
            }
        }
        vector<string> ans;
        ans.push_back(one);
        ans.push_back(two);
        ans.push_back(three);
        ans.push_back(forr);
        ans.push_back(five);
        return ans;
    }
};
int main() {
    for(auto tem: (new TapeMeasure())->draw(31, 38))
    {
        cout << tem << endl;
    }
}