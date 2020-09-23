#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
#define ls (node << 1)
#define rs ((node << 1) | 1)
typedef long long ll;
using namespace std;
int main()
{
    int n,A[112];
    int l = 2, r = n-1;
    while(l<r)
    {
        int mid = l + r >> 1;
        if (A[mid] < A[mid-1] and A[mid] < A[mid+1])
            return A[mid];
        if (A[mid] > A[mid-1])
            r = mid - 1;
        else
            l = mid + 1;
    }
    return A[l];
}