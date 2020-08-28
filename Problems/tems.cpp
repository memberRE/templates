#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
using namespace std;
vector<int> pic[23];
int main()
{
    auto tem = pic;
    tem[1].push_back(22);
    pic[1].push_back(11);
    for(auto i : tem[1])
        cout << i << " ";
}