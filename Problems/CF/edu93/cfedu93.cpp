#include <bits/stdc++.h>

using namespace std;
typedef long long LL;
int a[100000];
int main(){
    int t = 0;
    cin>>t;
    while(t--){
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }

        if(a[1] + a[2] <= a[n])printf("1 2 %d\n", n);
        else printf("-1\n");
    }
}