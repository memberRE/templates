#include<stdio.h>
#include<string.h>
typedef struct ppp{
	char name[53],author[23],pub[32],pubdate[13];
	int l,r,namelen,authorlen,publen,pubdatelen;
} lib;
lib pic[550];
int tot=1,root=1; 
char fin[55];
inline void add(int p,int now)
{
	while(p!=root && now)
	{
		int k=strcmp(pic[now].name,pic[p].name);
		if(k>0)
		{
			pic[p].r=now;
			pic[p].l=pic[now].l;
			pic[pic[p].l].r=p;
			pic[now].l=p;
			if(pic[p].r==root)
				root=p;
			break;
		}
		if(!pic[now].r)
		{
			pic[now].r=p;
			pic[p].l=now;
			break;
		}
		now=pic[now].r;
	}
}
int main()
{
	FILE *in,*out;
	in=fopen("books.txt","r");
	out=fopen("ordered.txt","w");
	while(fscanf(in,"%s %s %s %s",pic[tot].name,pic[tot].author,pic[tot].pub,pic[tot].pubdate)!=EOF)
	{
		pic[tot].namelen=strlen(pic[tot].name);
		pic[tot].authorlen=strlen(pic[tot].author);
		pic[tot].publen=strlen(pic[tot].pub);
		pic[tot].pubdatelen=strlen(pic[tot].pubdate);
		tot++;
		add(tot-1,root);
	}
	while(1)
	{
		int opt;
		scanf("%d",&opt);
		if(opt==0)	break;
		if(opt==1)
		{
			scanf("%s %s %s %s",pic[tot].name,pic[tot].author,pic[tot].pub,pic[tot].pubdate);
			pic[tot].namelen=strlen(pic[tot].name);
			pic[tot].authorlen=strlen(pic[tot].author);
			pic[tot].publen=strlen(pic[tot].pub);
			pic[tot].pubdatelen=strlen(pic[tot].pubdate);
			tot++;
			add(tot-1,root);
		}
		else if(opt==2)
		{
			scanf("%s",fin);
			int now=root;
			while(now)
			{
				char *loca=strstr(pic[now].name,fin);
				if(loca!=NULL)
				{
					int i;
					printf("%s",pic[now].name);
					for(i=1;i<=50-pic[now].namelen;i++)
						putchar(' ');
					printf("%s",pic[now].author);
					for(i=1;i<=20-pic[now].authorlen;i++)
						putchar(' ');
					printf("%s",pic[now].pub);
					for(i=1;i<=30-pic[now].publen;i++)
						putchar(' ');
					printf("%s",pic[now].pubdate);
					for(i=1;i<=10-pic[now].pubdatelen;i++)
						putchar(' ');
					putchar('\n');
				}
				now=pic[now].r;
			}
		}
		else if(opt==3)
		{
			scanf("%s",fin);
			int now=root;
			while(now)
			{
				char *loca=strstr(pic[now].name,fin);
				if(loca!=NULL)
				{
					if(now==root)
					{
						root=pic[now].r;
						pic[root].l=0;
					}
					else
					{
						int l=pic[now].l,r=pic[now].r;
						pic[l].r=r;
						pic[r].l=l;
						pic[0].l=pic[0].r=0;
					}
				}
				now=pic[now].r;
			}
		}
	}
	int now=root;
	while(now)
	{
		int i;
		fprintf(out,"%s",pic[now].name);
		for(i=1;i<=50-pic[now].namelen;i++)
			fputc(' ',out);
		fprintf(out,"%s",pic[now].author);
		for(i=1;i<=20-pic[now].authorlen;i++)
			fputc(' ',out);
		fprintf(out,"%s",pic[now].pub);
		for(i=1;i<=30-pic[now].publen;i++)
			fputc(' ',out);
		fprintf(out,"%s",pic[now].pubdate);
		for(i=1;i<=10-pic[now].pubdatelen;i++)
			fputc(' ',out);
		fputc('\n',out);
		now=pic[now].r;
	}
	fclose(in);
	fclose(out);
	return 0;
}
