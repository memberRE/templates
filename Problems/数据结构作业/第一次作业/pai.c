#include<stdio.h>
#include<string.h>
int vztd[12],stk[12];
void pai(int n,int num)
{
	int i;
	if(num==n)	
	{
		int j;
		for(j=0;j<n;++j)
		{
			if(stk[j]<10)
				putchar(stk[j]+'0');
			else
			{
				putchar('1');
				putchar('0');
			}
			putchar(' ');
		}
		putchar('\n');
		return;
	}
	for(i=1;i<=n;i++)
		if(!vztd[i])
		{
			vztd[i]=1;
			stk[num]=i;
			pai(n,num+1);
			vztd[i]=0;
		}
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	pai(n,0);
	return 0;
}
