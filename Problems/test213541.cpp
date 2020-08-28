#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int pic[55]={3,5,6,7,8,9,10,11,12,13};
	int k=lower_bound(pic+3,pic+7,99999)-pic;
	cout<<k<<endl;
	return 0;
}
