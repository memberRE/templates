#include<bits/stdc++.h>
using namespace std;
int main()
{
	unsigned int j1=0,j2=1;
	for(int i=2;;i++)
	{
		swap(j1,j2);
		j2+=j1;
		cout<<i<<' '<<j2<<endl;
		system("pause");
	}
}
