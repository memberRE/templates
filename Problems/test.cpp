#include <stdio.h>
int main()
{
    int a,b;
    int x=scanf("%d%d",&a,&b);
    if(x<2)
    {
        printf("error");
    }
    else
    {
        if(b==0)
        {
            printf("error");
        }
        else
        {
            int c;
            c=a/b;
            if(c>=0)
            {
                printf("%d",c);
            }
            else
            {
                printf("%d",c=c-1);
            }
        }
    }
    return 0;
}

