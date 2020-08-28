#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct list/*存储地址*/ 
{
	int data;
	struct list*nex;
};

struct trie/*维护一个单调的链表，每次读入单词插入链表，保证字典序单调递增，重复则统计次数*/ 
{
	struct trie*son[28];/*多个指针指向多个子节点，构成树形结构*/ 
	int frequency;/*frequency记录了位置个数*/ 
	char happen;
	//int locate[30];
	struct list *rot ,*endd;
};

int length;
char output[1030];

struct list* anspos[50005];/*出现位置*/ 

FILE*in,*out;

void finding(struct trie*u,int k)/*当前节点*/ 
{
	int i;
	if(u->frequency!=0)/*如果当前节点代表字符串出现过，则输出单词*/ 
	{
		if((u->frequency)==k)
		{
			for(i=0;i<length;i++)
			{
				fprintf(out,"%c",output[i]);
			}
			fprintf(out," %d",u->frequency);
			/*for(i=0;i<(u->frequency);i++)
			{
				//fprintf(out," %d",u->locate[i]);
			}*/
			struct list * noww=u->rot;
			for(;;noww=noww->nex)
			{
				fprintf(out," %d",noww->data);
				if(noww==u->endd)
					break;
			}
			fprintf(out,"\n");
		}
	}
	for(i=0;i<26;i++)
	{
		if(u->son[i]!=NULL)/*访问下一节点，更新路径字符*/
		{
			output[length]=i+'a';
			length++; 
			finding(u->son[i],k);/*递归*/
			length--;
		}
	}
}

char input[1030];

int capital(char a)/*大小写转换*/ 
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

struct trie*memory()/*申请空内存*/
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
			else/*插入字符数组单词*/
			{
				struct trie*now=root;
				int j;
				for(j=0;j<length;j++)
				{
					if(now->son[output[j]-'a']==NULL)/*有单词下一位但是无节点，则创建节点*/
					{
						struct trie*p=memory();
						now->son[output[j]-'a']=p; 
					}
					now=now->son[output[j]-'a'];/*前进*/
					if(j==length-1)/*到达结尾且在字典中出现*/ 
					{
						(now->happen)=1; 
					} 
				}
				length=0;
			}
		}
	}
	if(length!=0)/*特判*/
	{
		struct trie*now=root;
		int j;
		for(j=0;j<length;j++)
		{
			if(now->son[output[j]-'a']==NULL)/*有单词下一位但是无节点，则创建节点*/
			{
				struct trie*p=memory();
				now->son[output[j]-'a']=p; 
			}
			now=now->son[output[j]-'a'];/*前进*/
			if(j==length-1)/*到达结尾且在字典中出现*/ 
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
	int location=0;/*location记录了当前位置*/
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
			else/*检查字符数组单词*/
			{
				struct trie*now=root;
				int j;
				for(j=0;j<length;j++)
				{
					if(now->son[output[j]-'a']==NULL)/*有单词下一位但是无节点，则创建节点*/
					{
						struct trie*p=memory();
						now->son[output[j]-'a']=p; 
					}
					now=now->son[output[j]-'a'];/*前进*/
					if(j==length-1&&(now->happen)==0)/*到达结尾且不在字典中出现*/ 
					{
						//now->locate[now->frequency]=location;
						struct list * tem=(struct list *)malloc(sizeof(struct list));
						memset(tem,0,sizeof(struct list));
						tem->data=location;
						if(now->rot==NULL)
							now->rot=now->endd=tem;
						else
						{
							now->endd->nex=tem;
							now->endd=tem;
						}
						(now->frequency)++;
						maxfrequency=(maxfrequency>(now->frequency)?maxfrequency:(now->frequency));
					} 
				}
				location+=(length+1);
				length=0;
			}
		}
	}
	if(length!=0)/*特判*/
	{
		struct trie*now=root;
		int j;
		for(j=0;j<length;j++)
		{
			if(now->son[output[j]-'a']==NULL)/*有单词下一位但是无节点，则创建节点*/
			{
				struct trie*p=memory();
				now->son[output[j]-'a']=p; 
			}
			now=now->son[output[j]-'a'];/*前进*/
			if(j==length-1&&(now->happen)==0)/*到达结尾且不在字典中出现*/ 
			{
				//now->locate[now->frequency]=location;
				struct list * tem=(struct list *)malloc(sizeof(struct list));
				memset(tem,0,sizeof(struct list));
				tem->data=location;
				if(now->rot==NULL)
					now->rot=now->endd=tem;
				else
				{
					now->endd->nex=tem;
					now->endd=tem;
				}
				(now->frequency)++;
				maxfrequency=(maxfrequency>(now->frequency)?maxfrequency:(now->frequency));
			} 
		}
		length=0;/*finding函数中用到了length*/ 
	}
	int j;
	for(j=maxfrequency;j>=1;j--)
	{
		finding(root,j);
	//	printf("1");
	}
	fclose(in); 
	fclose(out); 
	return 0; 
}

