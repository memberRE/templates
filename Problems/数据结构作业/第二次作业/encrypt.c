#include<stdio.h>
#include<string.h>
char s[55],t[50];
char a[1000];
int cnt[30];
int lens,lent;
int main()
{
	gets(s);
	FILE *in,*out;
	in=fopen("encrypt.txt","r");
	out=fopen("output.txt","w");
	int i,k=0;
	for(i=0;s[i];i++)
		if(cnt[s[i]-'a']==0)
		{
			t[k]=s[i];
			cnt[s[i]-'a']++;
			k++;
		}
	for(i='z';i>='a';i--)
		if(cnt[i-'a']==0)
		{
			t[k]=i;
			cnt[i-'a']++;
			k++;
		}
	while(fgets(a,1002,in)!=NULL)
	{
		for(i=0;a[i];++i)
		{
			if(a[i]>='a' && a[i]<='z')
				fputc(t[a[i]-'a'],out);
			//	putchar(t[a[i]-'a']);
			else
				fputc(a[i],out);
			//	putchar(a[i]);
		}
	}
	fclose(in);
	fclose(out);
	return 0;
}
