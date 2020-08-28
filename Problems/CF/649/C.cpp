#include <algorithm>
#include<iostream>
#include<cstdio>
#include<cstring>
#include <queue>
using namespace std;
const int MAX = 1e5 + 50;
int A[MAX];
int B[MAX];
deque<int> que;
int main()
{
    memset(B, -1, sizeof(B));
    int n;
    cin >> n;
    for (int i = 1; i <= n;i++)
        cin >> A[i];
    if (A[1] == 1)
        B[1] = 0;
    else if (A[1] == 0)
        B[1] = 1;
    else
    {
        cout << -1;
        return 0;
    }
    int curB = B[1];
    for (int i = 2; i <= n;i++)
    {
        if(A[i] == A[i-1])
            que.push_back(i);
        else
        {
            if(curB < A[i-1])
            {
                B[i] = A[i-1];
                curB++;
                while(!que.empty())
                {
                    if(curB == A[i] - 1)
                        break;
                    int x = que.back();
                    que.pop_back();
                    B[x] = ++curB;
                    
                }
                if (curB != A[i] - 1)
                {
                    cout << -1 << endl;
                    return 0;
                }
                //curB = A[i] - 1;
                
            }
            else if (curB > A[i-1])
            {
                B[i] = 0;
                if (A[i] > curB + 1)
                {
                    cout << -1 << endl;
                    return 0;
                }
            }
            else {
                cout << -1 << endl;
                return 0;
            }
        }
    }
    while(!que.empty())
    {
        int x = que.front();
        que.pop_front();
        B[x] = 1000000;
    }
    for (int i = 1; i <= n; i++)
        printf("%d ", B[i]);
    return 0;
}