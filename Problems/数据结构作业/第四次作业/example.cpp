#include<string.h>
#include<stdio.h>
char s[256],ans[256];
int stk[256],top=0;
int flagdy=0,flagsy=0;
int main()
{
	FILE *in;
	in=fopen("example.c","r");
	int line=0;
	while(fgets(s,250,in)!=NULL)
	{
		line++;
		int i;
		for(i=0;s[i];i++)
		{
			if(s[i]==39)//µ¥ÒýºÅ 
				flagdy^=1;
			if(s[i]==34)
				flagsy^=1;
			
		}
	}
}
