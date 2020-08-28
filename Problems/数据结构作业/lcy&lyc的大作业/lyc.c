#include <stdio.h>
#include <string.h> 
#include <stdlib.h>
#include <ctype.h>
#define MAXDIC 450000
#define MAXMIS 3000
typedef struct dictionary{
	char word[51];
	struct dictionary *next;
	
}d; 
d *hash[MAXDIC];

typedef struct misspelling{
	char word[51];
	unsigned int loc[2000];
	int times;
	struct misspelling *next; 
}ms;
ms *misp[MAXMIS],*hashw[MAXDIC];

FILE *in1,*in2,*out;
int missum=-1;

void getdictionary();
void getarticle();
int searchdic(unsigned int h,char tp[]);
//int compare(char a[],char b[]);
void quick(int left,int right);
void swap(int i,int j);
void printlist();
unsigned int hashf(unsigned int h,char c);

int main(){
	in1=fopen("dictionary.txt","r");
	in2=fopen("article.txt","r");
	out=fopen("misspelling.txt","w");
	getdictionary();
	getarticle();
	quick(0,missum);
	printlist();
	fclose(in1);
	fclose(in2);
	fclose(out);
	return 0;
}

void getdictionary(){//创建字典哈希表 
	d *p,*q;
	char c,tp[51];
	unsigned int h=0;
	int i=0;
	do{
		c=fgetc(in1); 
		if(isalpha(c)){
			tp[i++]=c;
			h=hashf(h,c);
		}
		else if(!isalpha(c)&&i!=0){
			tp[i]='\0';
			q=(d *)malloc(sizeof(d));
			q->next=NULL; 
			strcpy(q->word,tp);
			if(!hash[h]){
				hash[h]=q;
			}
			else{
				for(p=hash[h];p->next!=NULL;p=p->next)
					;
				p->next=q;
			}
			i=h=0;
		}
	}while(c!=EOF); 
}
void getarticle(){//阅读文章 
	ms *p,*q,*before=NULL;
	char c,tp[51];
	unsigned int h=0;
	int i=0,sign;
	unsigned int seat=-1;
	do{
		c=fgetc(in2);
		if(c!='\r')
		++seat;
		else
		  continue;
		if(isalpha(c)){
			c=tolower(c);
			tp[i++]=c;
			h=hashf(h,c);
		}
		else if(!isalpha(c)&&i!=0){
			tp[i]='\0';
			sign=searchdic(h,tp);
			if(sign==0){//错词 
				if(!hashw[h]){//错词本无，直接加 
					q=(ms *)malloc(sizeof(ms));
					q->next=NULL;
					strcpy(q->word,tp);
					q->times=1; 
					q->loc[0]=seat-i;
					misp[++missum]=q;
					hashw[h]=q;
				}
				else{
					for(p=hashw[h];p!=NULL;before=p,p=p->next){
						if(strcmp(p->word,tp)==0){//错词本有 
							p->loc[p->times]=seat-i;
							p->times++;
							break;
						}
					}
					if(p==NULL){//错词本无 
						q=(ms *)malloc(sizeof(ms));
						q->next=NULL;
						strcpy(q->word,tp);
						q->times=1; 
						q->loc[0]=seat-i;
						before->next=q;
						q->next=p;
						misp[++missum]=q;
						hashw[h]=q;
					}	
				}
			}
			i=h=0; 
		}
	}while(c!=EOF);
}
int searchdic(unsigned int h,char tp[]){
	d *p;
	if(hash[h]){ 
		for(p=hash[h];p!=NULL;p=p->next){
			if(strcmp(tp,p->word)==0){
				return 1;
			}
		}
	}
	return 0;
}
//int compare(char a[],char b[]){
//	int i=0,j=0,sign=1;
//	while(a[i]&&b[j]){
//		if(a[i]!=b[j]){
//			sign=0;
//			break; 
//		}
//		i++;
//		j++;
//	}
//	if(!a[i]&&!b[i]&&sign==1){
//		return 1;
//	}
//	else return 0;
//}
void quick(int left,int right){     
    int i,j;
	ms *p; 
    if(left<right){
        i=left;j=right+1;
		p=misp[left];
		while(1){
			do{
			}while((misp[++i]->times>p->times||(misp[i]->times==p->times&&strcmp(misp[i]->word,p->word)<0))&&i!=right);
			do{
			}while((misp[--j]->times<p->times||(misp[j]->times==p->times&&strcmp(misp[j]->word,p->word)>0))&&j!=left);
			if(i<j)swap(i,j);
			else break;
		} 
		swap(left,j);
		quick(left,j-1);
		quick(j+1,right);    
    }
}

void printlist(){
	int i,j;
	for(i=0;i<=missum;i++){
		fprintf(out,"%s %d",misp[i]->word,misp[i]->times);
		for(j=0;j<misp[i]->times;j++){
			fprintf(out," %u",misp[i]->loc[j]);
		} 
		fputc('\n',out);
	}
}
void swap(int i,int j){
	ms *tmp;
	tmp=misp[i];
	misp[i]=misp[j];
	misp[j]=tmp;
} 
unsigned int hashf(unsigned int h,char c){
	return ((h<<5)+h+c-'\0')%MAXDIC;
} 
