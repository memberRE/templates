#include <stdio.h>
#include <string.h>
//char *str(char *s1,char *s2);
char *str(char* s1, char* s2)
{
 	char *p=s1;
 	for(;*p!='\0';p++)
 		  ;
 	for(;*s2!='\0';s2++,p++)
 		*p=*s2;
 		*p='\0';
	 return s1;    
 }
int main()
{
	char s1[100],s2[100];
	char * s;
	gets(s1);
	gets(s2);
	 s=str(s2,s1);
	puts(s);
	return 0;
 } 

