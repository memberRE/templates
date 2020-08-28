#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include<unordered_map>
#include <iostream>
using namespace std;
//unordered_map<int, int> vztd[3][3][3][3];
/*
number of shapes (one, two, or three)
shape (diamond, squiggle, or oval)
shading (solid, striped, or open)
color (red, green, or purple)
*
*/
int vztd[4][4][4][4];
char s[128];
int pic[260][4];
void chai(int fea[])
{
    int tem = 1;
    if (s[tem] == '*')
        fea[0] = 3, tem += 3;
    else if (s[tem] == 'o')
        fea[0] = 0, tem += 5;
    else if (s[tem + 1] == 'w')
        fea[0] = 1, tem += 5;
    else
        fea[0] = 2, tem += 7;

    if (s[tem] == '*')
        fea[1] = 3, tem += 3;
    else if (s[tem] == 'd')
        fea[1] = 0, tem += 9;
    else if (s[tem] == 's')
        fea[1] = 1, tem += 10;
    else
        fea[1] = 2, tem += 6;

    if (s[tem] == '*')
        fea[2] = 3, tem += 3;
    else if (s[tem + 1] == 'o')
        fea[2] = 0, tem += 7;
    else if (s[tem + 1] == 't')
        fea[2] = 1, tem += 9;
    else
        fea[2] = 2, tem += 6;

    if (s[tem] == '*')
        fea[3] = 3, tem += 3;
    else if (s[tem] == 'r')
        fea[3] = 0, tem += 5;
    else if (s[tem] == 'g')
        fea[3] = 1, tem += 7;
    else
        fea[3] = 2, tem += 8;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        memset(vztd, 0, sizeof(vztd));
        scanf("%d", &n);
        for (int i = 1; i <= n;i++)
        {
            scanf("%s", s);
            //int fea[4];
            chai(pic[i]);
            vztd[pic[i][0]][pic[i][1]][pic[i][2]][pic[i][3]] = 1;
        }
        for (int i = 1; i <= n;i++)
            for (int j = i + 1; j <= n;j++)
            {
                int can[4][4];
                if (pic[i][0])
            }
    }
}