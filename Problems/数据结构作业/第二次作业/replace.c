#include<stdio.h>
#include<string.h>
char s[500],t[500];
char a[1000];
int lens,lent;
inline int check(char a,char b)
{
	if(a>='a' && a<='z')
		a-=32;
	if(b>='a' && b<='z')
		b-=32;
	return a==b?1:0;
}
int main()
{
	gets(s);
	gets(t);
	lens=strlen(s);
	FILE *in,*out;
	in=fopen("filein.txt","r");
	out=fopen("fileout.txt","w");
	while(fgets(a,1002,in)!=NULL)
	{
		int i;
		for(i=0;a[i];++i)
		{
			if(!check(a[i],s[0]))
				fputc(a[i],out);
			//	putchar(a[i]);
			else
			{
				int k=1;
				for(;s[k];k++)
					if(!check(s[k],a[i+k]))
						break;
				if(s[k]==0)
				{
					fprintf(out,"%s",t);
				//	printf("%s",t);
					i+=k-1;
					
				}
				else
					fputc(a[i],out);
				//	putchar(a[i]);
			}
		}

	}
	fclose(in);
	fclose(out);
	return 0;
}
