#include<stdio.h>
#include<string.h>
char a[1000];
int main()
{
	gets(a);
	int i=0;
	for(;a[i];i++)
	{
		if(a[i]=='.')
			break;
	}
	if(i==1 && a[0]=='0')
	{
		for(i=2;a[i];i++)
			if(a[i]!='0')
				break;
		int num=i-1;
		putchar(a[i]);
		if(a[i+1])
			putchar('.');
		i++;
		for(;a[i];i++)
			putchar(a[i]);
		putchar('e');
		printf("%d",-num);
	}
	else
	{
		int num=i;
		putchar(a[0]);
		putchar('.');
		for(i=1;a[i];i++)
			if(a[i]!='.')
				putchar(a[i]);
		putchar('e');
		printf("%d",num-1);
	}                  
	return 0;
}
