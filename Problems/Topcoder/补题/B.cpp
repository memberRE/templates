#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
vector<string> S;
int sp[31][31];

class RoomPairs
{
public:
    vector<string> construct(int R, int C, int N)
    {
        S.clear();
        int x, y;

        //ZERO(sp);

        if (N == 2)
        {
            if (R == 2 && C == 2)
                return {};
            sp[0][0] = sp[R - 1][C - 1] = 1;
        }
        else if (C > R)
        {
            for (y = 0; y < R; y++)
            //FOR(y, R)
            {
                for (x = 0; x < C; x++)
                //FOR(x, C)
                {
                    int add = 2;

                    if (N == 1 && y < R - 1 && x < C - 1)
                    {
                        sp[R - 1][C - 1] = 1;
                        N -= 1;
                    }

                    if (x == 0 || y == R - 1)
                        add--;
                    if (N >= add)
                        sp[y][x] = 1, N -= add;
                }
            }
        }
        else
        {
            //FOR(x, C)
            for (x = 0; x < C; x++)
            {
                //FOR(y, R)
                for (y = 0; y < R; y++)
                {
                    int add = 2;
                    if (N == 1 && y < R - 1 && x < C - 1)
                    {
                        sp[R - 1][C - 1] = 1;
                        N -= 1;
                    }

                    if (y == 0 || x == C - 1)
                        add--;
                    if (N >= add)
                        sp[y][x] = 1, N -= add;
                }
            }
        }

        //FOR(y, 2 * R + 1)
        for (y = 0; y < 2 * R + 1; y++)
        {
            S.push_back(string(2 * C + 1, ' '));
            if (y % 2 == 0)
            {
                for (x = 0; x <= 2 * C; x += 2)
                    S[y][x] = '+';
            }
            if (y == 0 || y == 2 * R)
                for (x = 1; x <= 2 * C; x += 2)
                    S[y][x] = '-';
            if (y % 2)
                S[y][0] = S[y][2 * C] = '|';
        }

        //FOR(y, R)
        //FOR(x, C)
        for (y = 0; y < R; y++)
            for (x = 0; x < C; x++)
            {
                if (y + 1 < R && (sp[y][x] || sp[y + 1][x]))
                    S[2 * (y + 1)][x * 2 + 1] = '-';
                if (x + 1 < C && (sp[y][x] || sp[y][x + 1]))
                    S[y * 2 + 1][2 * (x + 1)] = '|';
            }

        //FORR(s, S)
        for (auto s : S)
            cout << s << endl;
        return S;
    }
};
int main()
{
    (new RoomPairs())->construct(4, 5, 31);
}