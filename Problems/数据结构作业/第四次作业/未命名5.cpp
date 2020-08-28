#include<stdio.h>
#include <stdlib.h> 
char stack_bracket[200], bracket[200] , linenum[1000]; 
int p_to_stack = -1 , p_to_bracket = -1;
int main()
{
	FILE *in;
	in = fopen("example.c", "r");
	int line = 1;
	
	
	char temp;
	int loop = 1;
	while(loop)
	{
		temp = fgetc(in);
		if(temp==EOF)  break;
	    else if(temp=='\n') line++;
		else if(temp=='"')        
		{
			while(1)
			{
				temp = fgetc(in);
				if(temp=='\\')  temp = fgetc(in);
				else if(temp=='"')  break;
			}
		}
		else if(temp=='\'')    
		{
			while(1)
			{
				temp = fgetc(in);
				if(temp=='\\')  temp = fgetc(in);
				else if(temp=='\'')  break;
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
			stack_bracket[++p_to_stack] = temp;
			bracket[++p_to_bracket] = temp;
			linenum[p_to_stack] = line;
		}
		
		else if(temp=='{')
		{
			stack_bracket[++p_to_stack] = temp;
			bracket[++p_to_bracket] = temp;
			linenum[p_to_stack] = line;
		}
		
		else if(temp==')')
		{
			bracket[++p_to_bracket] = temp;
			linenum[p_to_stack] = line;
			if(p_to_stack == -1)   
			{
				printf("without maching '%c' at line %d\n", temp, line);
				return 0;     
			}
			else 
			{
				if( stack_bracket[p_to_stack]=='(' )    
				{
					p_to_stack--;
				}
				else    
				{
					printf("without maching '%c' at line %d\n", temp, line);
					return 0;
				}
			}
			
		}
		
		else if(temp=='}')
		{
			bracket[++p_to_bracket] = temp;
			linenum[p_to_stack] = line;
			if(p_to_stack == -1)
			{
				printf("without maching '%c' at line %d\n", temp, line);
				return 0;
			}
			else
			{
				if( stack_bracket[p_to_stack]=='{' )
				{
					p_to_stack--;
				}
				else
				{
					printf("without maching '%c' at line %d\n", temp, line);
					return 0;
				}
			}
		}
		else 
		continue;
	}
	if(p_to_stack==0) 
	{
		printf("without maching '%c' at line %d\n",stack_bracket[p_to_stack] , linenum[p_to_stack]);
		return 0;
	}
	bracket[++p_to_bracket] = '\0';
    printf("%s", bracket);  
    fclose(in);  
    return 0;  
	
}

