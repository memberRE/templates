const int MAX = 33, MOD = 998244353;
const char A = 'a', __plus = '+', __const_num = '3';
const int MODS = 17;
int p[5006], p2[5006], aa[5006];
int tot = 0;
int ans = 0;
int ans2 = 0;
int jkl = 33;
int get_sum(int rty)
{
    int __ans = 0;
    int i;
    for (i = 1; i < 2; i = i + 1)
    {
        if (i / rty > 1)
            __ans = __ans + 1;
        if (i == rty)
            __ans = __ans * -1;
        if (i != 4)
            __ans = __ans + 100;
        else
            __ans = __ans + 10000;
    }
    return (__ans);
}
char wuliao(char s, char t)
{
    const int uio = 10;
    return (s);
}
void main()
{
    int i, j;
    char kkk = wuliao(A, A);
    int jjj;
    int temm = jkl / __const_num;
    scanf(tot);
    for (i = 1; i <= tot; i++)
    {
        p[tot] = 1;
        p2[tot] = 1;
        scanf(aa[i]);
    }
    for (i = 2; i <= tot; i = i + 1)
        for (j = i - 1; j >= 1; j = j - 1)
        {
            if (aa[j] < aa[i])
            {
                if (p[i] <= p[j] + 1)
                {
                    p[i] = p[j] + 1;
                }
            }

            if (aa[j] > aa[i])
            {
                if (p2[i] <= p2[j] + 1)
                {
                    p2[i] = p2[j] + 1;
                }
            }
        }
    for (i = 1; i <= tot; i = i + 1)
    {
        if (ans <= p[i])
        {
            ans = p[i];
        }
        if (ans2 <= p2[i])
        {
            ans2 = p2[i];
        }
    }
    printf("18373665");
    printf("++", ans2);
    printf("++");
    printf(ans);
    //---------------------------test_const

    printf("++", jkl);
    printf("++", __plus);

    printf("++", temm);
    printf(MODS);

    jjj = get_sum(__const_num);
    printf(jjj);

    printf(kkk);
    //-----------------------------
}