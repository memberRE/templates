#include<bits/stdc++.h>
using namespace std;
int n,m,A[55][55],B[55][55];
int ansi[2510],ansj[2510],cnt;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	for(int i=1;i<n;i++)
	{
		if(i!=n)
		{
			for(int j=1;j<m;j++)
			{
				if(A[i][j]==B[i][j] and A[i][j]==1)
				{
					if(A[i+1][j]==1 and A[i][j+1]==1 and A[i+1][j+1]==1)
					{
						B[i][j]=B[i+1][j]=B[i][j+1]=B[i+1][j+1]=1;
						cnt++;
						ansi[cnt]=i;
						ansj[cnt]=j;
					}
				}
				if(A[i][j]==1 and B[i][j]==0)
				{
					B[i][j]=B[i+1][j]=B[i][j+1]=B[i+1][j+1]=1;
					cnt++;
					ansi[cnt]=i;
					ansj[cnt]=j;
				}	
				else if(A[i][j]==0 and B[i][j]==1)
				{
					cout<<"-1";
					return 0;
				}
			}	
		}
	}
//		else
//		{
//			for(int j=1;j<m;j++)
//			{
//				if(A[i][j]==B[i][j])
//					continue;
//				if(A[i][j]==1 and B[i][j]==0)
//				{
//					B[i][j]=B[i+1][j]=B[i][j+1]=B[i+1][j+1]=1;
//					cnt++;
//					ansi[cnt]=i-1;
//					ansj[cnt]=j;
//				}	
//				else if(A[i][j]==0 and B[i][j]==1)
//				{
//					cout<<"-1";
//					return 0;
//				}
//			}	
//		}
//	}
//	for(int j=1;j<m;j++)
//	{
//		int i=n;
//		if(A[i][j]!=B[i][j])
//		{
//			B[i][j]=B[i][j+1]=B[i-1][j]=B[i-1][j+1]=1;
//			cnt++;
//			ansi[cnt]=i-1;
//			ansj[cnt]=j;
//		}	
//	}
//	for(int i=1;i<n;i++)
//	{
//		int j=m;
//		if(A[i][j]!=B[i][j])
//		{
//			B[i][j]=B[i+1][j]=B[i][j-1]=B[i+1][j-1]=1;
//			cnt++;
//			ansi[cnt]=i;
//			ansj[cnt]=j-1;
//		}	
//	}
//	if(A[n][m]!=B[n][m])
//	{
//		B[n][m]=B[n-1][m]=B[n][m-1]=B[n-1][m-1]=1;
//		cnt++;
//		ansi[cnt]=n-1;
//		ansj[cnt]=m-1;
//	}
//		
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(A[i][j]!=B[i][j])
			{
				cout<<"-1";
				return 0;
			}
		}
	cout<<cnt<<endl;
	for(int i=1;i<=cnt;i++)
		cout<<ansi[i]<<' '<<ansj[i]<<endl;
	return 0;
}
