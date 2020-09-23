//CF round 666 B 
int max(int a, int b)
{
    if (a > b)
        return a;
    else if (a < b)
        return b;
}
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int sum = 0;
        int maxx = 0;
        for (int i = 1; i <= n; i++)
        {
            int tem;
            scanf("%d", &tem);
            sum += tem;
            maxx = max(tem, maxx);
        }
        if (maxx > sum - maxx || sum % 2 == 1)
            printf("T");
        else
            printf("HL");
    }
    return 0;
}