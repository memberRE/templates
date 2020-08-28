#include<stdio.h>
#include<string.h>
int stk[150],top=0;
int main()
{
	while(1)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==-1)	break;
		if(opt==1)
		{
			int jkl;
			scanf("%d",&jkl);
			if(top==100)
				printf("error ");
			else
				stk[top++]=jkl;
		}
		else
		{
			if(top)
				printf("%d ",stk[--top]);
			else
				printf("error "); 
		}
	}
	return 0;
}
