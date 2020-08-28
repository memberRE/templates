#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
using namespace std;
struct ppp{
	long long calc;
	int sum;
	bool operator < (const ppp& a)	const{
		return calc<a.calc;
	}
}pic[100003];
long long ans[100003];
int cnt=0;
int main()
{
	memset(pic,0,sizeof(pic));
	for(int i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
		{
			long long ans=0;
			for(int I=1;I<=i;I++)
				for(int J=1;J<=j;J++)
					ans+=(i-I+1)*(j-J+1);
			cnt++;
			pic[cnt].calc=ans;
			pic[cnt].sum=i*j;
	//		cout<<ans<<' ';
		}
	//	cout<<endl;
	//	system("pause");
	}	
	for(int i=101;i<=250;i++)
	{
		for(int j=1;j<=28;j++)
		{
			long long ans=0;
			for(int I=1;I<=i;I++)
				for(int J=1;J<=j;J++)
					ans+=(i-I+1)*(j-J+1);
			cnt++;
			pic[cnt].calc=ans;
			pic[cnt].sum=i*j;
	//		cout<<ans<<' ';
		}
	//	cout<<endl;
	//	system("pause");
	}	
	for(int i=251;i<=650;i++)
	{
		for(int j=1;j<=10;j++)
		{
			long long ans=0;
			for(int I=1;I<=i;I++)
				for(int J=1;J<=j;J++)
					ans+=(i-I+1)*(j-J+1);
			cnt++;
			pic[cnt].calc=ans;
			pic[cnt].sum=i*j;
	//		cout<<ans<<' ';
	//	cout<<ans<<endl;
		}
	//	cout<<endl;
	//	system("pause");
	}	
	for(int i=651;i<=2000;i++)
	{
		for(int j=1;j<=3;j++)
		{
			long long ans=0;
			for(int I=1;I<=i;I++)
				for(int J=1;J<=j;J++)
					ans+=(i-I+1)*(j-J+1);
			cnt++;
			pic[cnt].calc=ans;
			pic[cnt].sum=i*j;
		}
	}	
	sort(pic+1,pic+1+cnt);
	for(int i=1;i<=cnt;i++)
		ans[i]=pic[i].calc;
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		long long jkl;
		cin>>jkl;
		int A=lower_bound(ans+1,ans+1+cnt,jkl)-ans;
		int B=A+1,C=A-1;
		if(B<=cnt and C>0)
		if(abs(ans[A]-jkl)>abs(ans[B]-jkl))
			swap(A,B);
		if(abs(ans[A]-jkl)>abs(ans[C]-jkl))
			swap(A,C);
		cout<<pic[A].sum<<endl;
	}
	return 0;
}
