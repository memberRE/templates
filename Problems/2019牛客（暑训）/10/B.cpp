#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[512];
char s[10][50]={" "," COFFEE"," CHICKEN"," COFFEECHICKEN"," CHICKENCOFFEECHICKEN"};
void dfs(int n,ll k,int flag)
{
	if(n<=4)
	{
		if(k>=50)
		{
			cout<<"788"<<endl;
			return;
		}
		if(flag)
		{
			int cnt=0;
			ll jkl=strlen(s[n]);
			for(ll i=k;i<jkl and cnt<10;i++)
				putchar(s[n][i]),cnt++;
			return ;
		}
		else
		{
			for(ll i=1;i<=k and s[n][i];i++)
				putchar(s[n][i]);
			return ;
		}
	}
	else
	{
		if(flag)
		{
			if(k>f[n-2])
				dfs(n-1,k-f[n-2],1);
			else if(k+9ll>f[n-2])
			{
				dfs(n-2,k,1);
				dfs(n-1,9ll-f[n-2]+k,0);
			}
			else
				dfs(n-2,k,1);
		}
		else
		{
			if(k<=f[n-2])
				dfs(n-2,k,0);
			else
			{
				dfs(n-2,1,1);
				dfs(n-1,k-f[n-2],0);
			}
		}
	}
}
int main()
{
	f[1]=6ll;
	f[2]=7ll;
	f[3]=13ll;
	f[4]=20ll;
	f[5]=33ll;
	f[6]=53ll;
	f[7]=86ll;
	f[8]=139ll;
	f[9]=225ll;
	f[10]=364ll;
	f[11]=589ll;
	f[12]=953ll;
	f[13]=1542ll;
	f[14]=2495ll;
	f[15]=4037ll;
	f[16]=6532ll;
	f[17]=10569ll;
	f[18]=17101ll;
	f[19]=27670ll;
	f[20]=44771ll;
	f[21]=72441ll;
	f[22]=117212ll;
	f[23]=189653ll;
	f[24]=306865ll;
	f[25]=496518ll;
	f[26]=803383ll;
	f[27]=1299901ll;
	f[28]=2103284ll;
	f[29]=3403185ll;
	f[30]=5506469ll;
	f[31]=8909654ll;
	f[32]=14416123ll;
	f[33]=23325777ll;
	f[34]=37741900ll;
	f[35]=61067677ll;
	f[36]=98809577ll;
	f[37]=159877254ll;
	f[38]=258686831ll;
	f[39]=418564085ll;
	f[40]=677250916ll;
	f[41]=1095815001ll;
	f[42]=1773065917ll;
	f[43]=2868880918ll;
	f[44]=4641946835ll;
	f[45]=7510827753ll;
	f[46]=12152774588ll;
	f[47]=19663602341ll;
	f[48]=31816376929ll;
	f[49]=51479979270ll;
	f[50]=83296356199ll;
	f[51]=134776335469ll;
	f[52]=218072691668ll;
	f[53]=352849027137ll;
	f[54]=570921718805ll;
	f[55]=923770745942ll;
	f[56]=1494692464747ll;
	f[57]=2418463210689ll;
	f[58]=3913155675436ll;
	f[59]=6331618886125ll;
	f[60]=10244774561561ll;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		ll k;
		int n;
		scanf("%d%lld",&n,&k);
		while(n>60)
			n-=2;
		dfs(n,k,1);
		putchar('\n');
	}
	return 0;
}

