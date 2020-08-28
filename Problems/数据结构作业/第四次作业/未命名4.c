#include<stdio.h>
int main()
{
	char s[500];
	FILE *in;
	in=fopen("in.txt","r");
	while(fgets(s,200,in)!=NULL)
	{
		putchar('a');
		putchar('\n');
	}
	return 0;
}
