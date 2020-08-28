#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
#include<map>
using namespace std;
char s[23465];
void Miyaolenth(char c[]) 
{
  int klen=1;   //????
  int clen=strlen(c);   //????? 		     	
  while(1)
  {
        float IC[klen]; //????
	float avgIC=0;  //??????
	for(int i=0;i<klen;i++)    //???????? 
	{		
	    int out[26]={ 0 };   //?????????
		for(int j=0;i+j*klen<clen;j++)
		   out[(int)(c[i+j*klen]-'A')]++;  
        float e=0.000f;
        int L=0;
        for(int k=0;k<26;k++)    //?????? 
            L+=out[k];
        L*=(L-1);
	    for(int k=0;k<26;k++)        //????????IC 
	       if(out[k]!=0)
	           e=e+((float)out[k]*(float)(out[k]-1))/(float)L;
		IC[i]=e;
    }
	for(int i=0;i<klen;i++)
	   avgIC+=IC[i];
	avgIC/=klen;          //?IC????  
    if (avgIC >= 0.06)  break;    //??????,????????????0.06 
    else  klen++;
  }
  cout<<"length:"<<klen<<endl; 
  float p[] = {0.082, 0.015, 0.028, 0.043, 0.127, 0.022, 0.02, 0.061, 0.07, 0.002, 0.008, 0.04, 0.024, 0.067, 0.075, 0.019, 0.001, 0.06, 0.063, 0.091, 0.028, 0.01, 0.023, 0.001, 0.02, 0.001};
	klen=20;
	int key[100]={ 0 };    //???? 
	for(int i=0;i<klen;i++)    //???????? 
	{	
	  int g=0;   //????g??? 
	  for(int t=0;t<26;t++)
	  {
	 	float x=0.000f;    //????? 	
	    int out[26]={ 0 };   //?????????
		for(int j=0;i+j*klen<clen;j++)
		   out[(int)(c[i+j*klen]-'A')]++;  
        int L=0;
        for(int k=0;k<26;k++)      //?????? 
            L+=out[k];
        for(int k=0;k<26;k++)
            x=x+p[k]*out[(k+g)%26];
        if(x/L>0.055)
        {
        	key[i]=g;
        	break;
		}
        else g++;
	   }
    }
   cout<<endl; 
   for(int i=0;i<klen;i++)    //????? 
		cout<<char ('a'+key[i]);
   cout<<endl;

}

int pic[30];
int main()
{
//	cin>>s;
	cin.getline(s,99999);
	memset(pic,0,sizeof(pic));
	for(int i=0;i<strlen(s);i++)
	s[i]-=32;
		//pic[s[i]-'a']++;
/*	for(int i=0;i<=25;i++)
	{
		cout<<(char)('a'+i)<<' '<<pic[i]<<endl;
	}
	double ci=0.0;*/
	Miyaolenth(s);
/*	for(int i=0;i<=25;i++)
		ci+=(((pic[i]*1.0)/(strlen(s)*1.0))*((pic[i]*1.0)/(strlen(s)*1.0)));
	cout<<ci;*/
	return 0;
}
