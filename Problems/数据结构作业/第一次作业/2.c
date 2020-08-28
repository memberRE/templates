#include<stdio.h>
#include<string.h>
char a[3000];
inline int iden(char a)
{
	if(a>='0' && a<='9')
		return 1;
	if(a>='a' && a<='z')
		return 2;
	if(a>='A' && a<='Z')
		return 3;
	return 0;
}
int main()
{
	gets(a);
	int i,typ=0;
	for(i=0;a[i];i++)
	{
		if(a[i]!='-')
			putchar(a[i]);
		else
		{
			int pre=a[i-1],nex=a[i+1];
			int idpre=iden(pre),idnex=iden(nex);
			if(idpre==idnex && idpre!=0)
			{
				char j=a[i-1]+1;
				for(;j<a[i+1];++j)
					putchar(j);
				if(j!=a[i+1])
					putchar('-');
				continue;
			}
			putchar('-');
		}
	}
	return 0;
} 
