#include<iostream>
#include <cstdio>
#include <algorithm>
#include<cmath>
#include<queue>
#include <string>
using namespace std;
const int MAX = 2e5 + 20;
typedef long long  ll;
int pic[MAX],n;
struct ppp{
    ll val;
    int id;
    bool operator < (const ppp &a) const 
    {
        return val > a.val;
    }
} store[MAX];
int vztd[MAX];
priority_queue<ppp> que;
int main()
{
    cin >> n;
    for (int i = 1; i <= n;i++)
    {
        scanf("%lld", &store[i].val);
        store[i].id = i;
    }
    store[0].val = store[n].val;
    store[n + 1].val = store[1].val;
}