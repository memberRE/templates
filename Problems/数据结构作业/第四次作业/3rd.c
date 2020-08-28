#include<stdio.h>
#include <stdlib.h> 
char stk[205],ans[205];
int stkline[1005]; 
int top=-1,cnt=-1,line=1;
int main()
{
	FILE *in;
	in=fopen("example.c", "r");
	char temp;
	while(1)
	{
		temp = fgetc(in);
		if(temp==EOF)  break;
	    else if(temp=='\n') line++;
		else if(temp=='"')        
		{
			while(1)
			{
				temp = fgetc(in);
			//	if(temp=='\\')  temp = fgetc(in);
			/*	else*/ if(temp=='"')  break;
			}
		}
		else if(temp=='\'')    
		{
			while(1)
			{
				temp = fgetc(in);
			/*	if(temp=='\\')  temp = fgetc(in);
				else if(temp=='\'')  break;*/
				if(temp=='\'')	break;
			}
		}
	    else if(temp=='/')        
	    {
	    	temp = fgetc(in);
	    	if(temp=='/')
	    	{
	    		while( (temp = fgetc(in)) != '\n' )  
	    		  ;
	    		line++;
			}
			else if(temp=='*')
			{
				int zhushi = 0;
				temp = fgetc(in);
				while(1)
				{
					if(zhushi)  break;
					while(temp != '*')
				   {
					   temp = fgetc(in);
					   if(temp == '\n')  line++;
				   }  
				   temp = fgetc(in);
				   if(temp=='\n') line++;
				   if(temp=='/') zhushi = 1;
				}
			}
		}
		
		else if(temp=='(')                          
		{
			stk[++top] = temp;
			ans[++cnt] = temp;
			stkline[top] = line;
		}
		
		else if(temp=='{')
		{
			if(top == -1)
			{
				stk[++top] = temp;
				ans[++cnt] = temp;
				stkline[top] = line;
			}
			else if(stk[top]==40)//(
			{
				printf("without maching '%c' at line %d",40,stkline[top]);
				return 0;
			}
			else
			{
				stk[++top]=temp;
				stkline[top]=line;
				ans[++cnt]=123;
				continue;
			}
		}
		
		else if(temp==')')
		{
			ans[++cnt] = temp;
			stkline[top] = line;
			if(top == -1)   
			{
				printf("without maching '%c' at line %d", temp, line);
				return 0;     
			}
			else 
			{
				if( stk[top]=='(' )    
				{
					top--;
				}
				else    
				{
					printf("without maching '%c' at line %d", temp, line);
					return 0;
				}
			}
			
		}
		
		else if(temp=='}')
		{
			ans[++cnt] = temp;
			stkline[top] = line;
			if(top == -1)
			{
				printf("without maching '%c' at line %d", temp, line);
				return 0;
			}
			else
			{
				if( stk[top]=='{' )
					top--;
				else
				{
					printf("without maching '%c' at line %d", temp, line);
					return 0;
				}
			}
		}
		else 
		continue;
	}
	if(top==0) 
	{
		printf("without maching '%c' at line %d",stk[top] , stkline[top]);
		return 0;
	}
	ans[++cnt] = '\0';
    puts(ans);
    fclose(in);  
    return 0;  
}

