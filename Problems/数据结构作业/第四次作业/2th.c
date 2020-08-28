#include<string.h>
#include<stdio.h>
char s[256],ans[256];
int stk[256],top=0,stkline[256],cnt=0; 
int flagdy=0,flagsy=0,flagzs=0;
int flag=0;
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
			if(flagzs==1)
			{
				if(s[i]=='*' && s[i+1]=='/')
				{
					flagzs=0;
					i++;
				}
				continue;
			}
//			if(s[i]==39)//单引号 
//				flagdy^=1;
//			if(s[i]==34)//双引号 
//				flagsy^=1;
//			if(flagdy==1 || flagsy==1)
//				continue;
			if(s[i]=='\'')
			{
				while(1)
				{
					i++;
					if(s[i]=='\'')
						break;
				}
				continue;
			}
			if(s[i]=='"')
			{
				while(1)
				{
					i++;
					if(s[i]=='"')
						break;
				}
				continue;
			}
			if(s[i]=='/' && s[i+1]=='/')//单行注释 
				break;
			if(s[i]=='/' && s[i+1]=='*')
			{
				flagzs=1;
				i++;
				continue;
			}
			if(s[i]==123) //{
			{
				if(!top)
				{
					stk[top]=123;
					stkline[top++]=line;
					ans[cnt++]=123;
					continue;
				}
				else if(stk[top-1]==40)//(
				{
					printf("without maching '%c' at line %d",40,stkline[top-1]);
					return 0;
				}
				else
				{
					stk[top]=123;
					stkline[top++]=line;
					ans[cnt++]=123;
					continue;
				}
			}
			else if(s[i]==125) //}
			{
				if(!top || stk[top-1]!=123)//{
				{
					printf("without maching '%c' at line %d",125,line);
					return 0;
				}
				else
				{
					ans[cnt++]=125;
					top--;
				}
			}
			else if(s[i]==40) //(
			{
				stk[top]=40;
				stkline[top++]=line;
				ans[cnt++]=40;
			}
			else if(s[i]==41)//)
			{
				if(!top || stk[top-1]!=40)//(
				{
					printf("without maching '%c' at line %d",41,line);
					return 0;
				}
				else
				{
					ans[cnt++]=41;
					top--;
				}
			}
		}
	}
	if(top==1)
	{
		printf("without maching '%c' at line %d",stk[top-1],stkline[top-1]);
		return 0;
	}
	ans[cnt++]='\0';
	puts(ans);
	fclose(in);
	return 0;
}

