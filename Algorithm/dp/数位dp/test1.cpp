#include <iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
   int t,i,j,n;
   char c;
   long long x;
   x=0;
   c=getchar();
   while(c!='\n')
   {
       int num=int(c)-int('0');
       x=(x*10+num)%9;
       c=getchar();
   }
   cout<<x<<endl;
}//

char arrayint[10000], n = '\0';
    long result = 0, i = 0;
    /*此处换成
    cin.get(arrayint, 10000);
    for (; arrayint[i] >= '0' && arrayint[i] <= '9'; i++) {
        result += (arrayint[i] - '0');
    }
        就过不去，然而我并不知道这两者有什么区别。。。。*/
    while (cin >> n && n >= '0' && n <= '9') {
        result += n - '0';
    }
