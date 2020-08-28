#include<stdio.h>
#include<string.h>
int e,si=0;
void minus (int *c,int *d)
{
	int i;
	for(i=0; i<=e-1; i++)
	{
		c[i]=c[i]-d[i];
		if(c[i]<0)
		{
			c[i+1]--;
			c[i]=c[i]+10;
		}
	}
}
void pri(int *c,int *d)
{
	int k=0,i,f=0;
	for(i=e-1; i>=0; i--)
		k=k+c[i];
	if(k==0)
		printf("%d\n",0);
	else
	{
		if(si)	printf("-");
		for(i=e-1; i>=0; i--)
		{
			if(f==0)
			{
				if(c[i]!=0)
				{
					f++;
					printf("%d",c[i]);
				}
			}
			else
			{
				f++;
				printf("%d",c[i]);
			}
		}
	}
}
int main()
{
	char a[100],b[100];
	char kjk;
	int c[100],d[100],i,cam;
	gets(a);
	gets(b);
	memset(c,0,sizeof(c));
	memset(d,0,sizeof(d));
	int lena=strlen(a),lenb=strlen(b);
	e=lena>=lenb?lena:lenb;
	for(i=lena-1; i>=0; i--)
		c[lena-1-i]=a[i]-48;
	for(i=lenb-1; i>=0; i--)
		d[lenb-1-i]=b[i]-48;
	cam=strcmp(a,b);
	if(lena>lenb)
	{
		minus(c,d);
		pri(c,d);
	}
	if(lena<lenb)
	{
		si++;
		minus(d,c);
		pri(d,c);
	}
	if(lena==lenb)
	{
		if(cam==0)
		{
			printf("0");
			return 0;
		}
		if(cam>0)
		{
			minus(c,d);
			pri(c,d);
		}
		if(cam<0)
		{
			si++;
			minus(d,c);
			pri(d,c);
		}
	}
	return 0;
}
