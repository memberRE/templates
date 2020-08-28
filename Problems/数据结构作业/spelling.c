#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct trie/*ά��һ������������ÿ�ζ��뵥�ʲ���������֤�ֵ��򵥵��������ظ���ͳ�ƴ���*/ 
{
	struct trie*son[28];/*���ָ��ָ�����ӽڵ㣬�������νṹ*/ 
	int frequency;
	char happen;
	int locate[100];
};

int length;
char output[1030];
FILE*in,*out;

void finding(struct trie*u,int k)/*��ǰ�ڵ�*/ 
{
	int i;
	if(u->frequency!=0)/*�����ǰ�ڵ�����ַ������ֹ������������*/ 
	{
		if((u->frequency)==k)
		{
			for(i=0;i<length;i++)
			{
				fprintf(out,"%c",output[i]);
			}
			fprintf(out," %d",u->frequency);
			for(i=0;i<(u->frequency);i++)
			{
				fprintf(out," %d",u->locate[i]);
			}
			fprintf(out,"\n");
		}
	}
	for(i=0;i<26;i++)
	{
		if(u->son[i]!=NULL)/*������һ�ڵ㣬����·���ַ�*/
		{
			output[length]=i+'a';
			length++; 
			finding(u->son[i],k);/*�ݹ�*/
			length--;
		}
	}
}

char input[1030];

int capital(char a)/*��Сдת��*/ 
{
	if(a>='A'&&a<='Z')
	{
		return a+32;
	}
	else
	{
		return a;
	}
}

struct trie*memory()/*������ڴ�*/
{
	struct trie*k=(struct trie*)malloc(sizeof(struct trie));
	memset(k,0,sizeof(struct trie));
	return k;
} 

int main()
{
	in=fopen("dictionary.txt","r");
	struct trie*root=memory();
	while(fgets(input,1030,in)!=NULL)
	{
		int i;
		for(i=0;input[i];i++)
		{
			input[i]=capital(input[i]);
			if(input[i]>='a'&&input[i]<='z')
			{
				output[length]=input[i];
				length++;
			}
			else/*�����ַ����鵥��*/
			{
				struct trie*now=root;
				int j;
				for(j=0;j<length;j++)
				{
					if(now->son[output[j]-'a']==NULL)/*�е�����һλ�����޽ڵ㣬�򴴽��ڵ�*/
					{
						struct trie*p=memory();
						now->son[output[j]-'a']=p; 
					}
					now=now->son[output[j]-'a'];/*ǰ��*/
					if(j==length-1)/*�����β�����ֵ��г���*/ 
					{
						(now->happen)=1; 
					} 
				}
				length=0;
			}
		}
	}
	if(length!=0)/*����*/
	{
		struct trie*now=root;
		int j;
		for(j=0;j<length;j++)
		{
			if(now->son[output[j]-'a']==NULL)/*�е�����һλ�����޽ڵ㣬�򴴽��ڵ�*/
			{
				struct trie*p=memory();
				now->son[output[j]-'a']=p; 
			}
			now=now->son[output[j]-'a'];/*ǰ��*/
			if(j==length-1)/*�����β�����ֵ��г���*/ 
			{
				(now->happen)=1; 
			} 
		}
		length=0;
	}
	fclose(in); 
	in=fopen("article.txt","r");
	out=fopen("misspeling.txt","w");
	int maxfrequency=0;
	int location=0;
	while(fgets(input,1030,in)!=NULL)
	{
		int i;
		for(i=0;input[i];i++)
		{
			input[i]=capital(input[i]);
			if(input[i]>='a'&&input[i]<='z')
			{
				output[length]=input[i];
				length++;
			}
			else/*����ַ����鵥��*/
			{
				struct trie*now=root;
				int j;
				for(j=0;j<length;j++)
				{
					if(now->son[output[j]-'a']==NULL)/*�е�����һλ�����޽ڵ㣬�򴴽��ڵ�*/
					{
						struct trie*p=memory();
						now->son[output[j]-'a']=p; 
					}
					now=now->son[output[j]-'a'];/*ǰ��*/
					if(j==length-1&&(now->happen)==0)/*�����β�Ҳ����ֵ��г���*/ 
					{
						now->locate[now->frequency]=location;
						(now->frequency)++;
						maxfrequency=(maxfrequency>(now->frequency)?maxfrequency:(now->frequency));
					} 
				}
				location+=(length+1);
				length=0;
			}
		}
	}
	if(length!=0)/*����*/
	{
		struct trie*now=root;
		int j;
		for(j=0;j<length;j++)
		{
			if(now->son[output[j]-'a']==NULL)/*�е�����һλ�����޽ڵ㣬�򴴽��ڵ�*/
			{
				struct trie*p=memory();
				now->son[output[j]-'a']=p; 
			}
			now=now->son[output[j]-'a'];/*ǰ��*/
			if(j==length-1&&(now->happen)==0)/*�����β�Ҳ����ֵ��г���*/ 
			{
				(now->frequency)++;
				maxfrequency=(maxfrequency>(now->frequency)?maxfrequency:(now->frequency));
			} 
		}
	}
	int j;
	for(j=maxfrequency;j>=1;j--)
	{
		finding(root,j);
	}
	fclose(in); 
	fclose(out); 
}
