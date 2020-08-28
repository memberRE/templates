#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include<deque>
using namespace std;
const int MAX = 1e6 + 20;
char S[MAX];
int sum[MAX],ans,max_0;
//int que[MAX], top;
deque<int> que;
int main()
{
    //int n;
    scanf("%s", S + 1);
    for (int i = 1; S[i];i++)
        sum[i] = sum[i - 1] + S[i] - '0',max_0 += abs(S[i] - '1');
    int m;
    scanf("%d", &m);
    while(m--)
    {
        que.clear();
        /*while(!que.empty())
        	que.pop_back();*/
        ans = 0;
        int k;
        scanf("%d", &k);
        for (int i = 1; S[i];i++)
        {
            int tem = i + 1 + k - 2 * sum[i];
            int ne = i - 2*sum[i - 1];
            while(!que.empty() and que.back() - 2*sum[que.back() - 1] >= ne)
                que.pop_back();
            que.push_back(i);
            while(!que.empty() and sum[i] - sum[que.front()  - 1] > k)
                que.pop_front();
            ans = max(ans, min(tem - (que.front() - 2*sum[que.front() - 1]),max_0));
        }
        printf("%d\n", ans);
    }
    return 0;
}
