#include <stdio.h>
#define INF 0xFFFFF
long long A[1000000];
long long number;

void Merge(int left, int mid, int right)
{
    int len1= mid - left +1;
    int len2 = right - mid;
    int L[len1+ 1], R[len2 +1];
    for(int i =0; i<len1; i++)
        L[i] = A[left +i];
    for(int i = 0; i<len2; i++)
        R[i] = A[mid+i+1];
    L[len1] =R[len2] =INF;
    int l = 0, r= 0;
    for(int i = left; i<= right; i++)
    {
        if(L[l] <= R[r])
            A[i] = L[l++];
        else
        {
            A[i] = R[r++];
            number += len1 - l;
        }
    }
}

void mergeSort(int left, int right)
{
    if(left<right)
    {
        int mid = (left + right)/2;
        mergeSort(left, mid);
        mergeSort(mid +1, right);
        Merge(left , mid, right);
    }
}

int main()
{
    long long n;
    while(scanf("%lld", &n)!=EOF)
    {
        number = 0;
        for(int i = 0; i<n; i++)
            scanf("%lld", &A[i]);
        mergeSort(0, n-1);
        printf("%lld\n", number);
    }
}
