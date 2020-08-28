#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
int n,m;
 
struct fun{
	long long a;
	long long s;
};
 
int b[1000000];
queue<fun>qq;
 
long long bfs(int v){
	memset(b,0,sizeof(b));
	fun t;
	t.a=v;
	t.s=0;
	qq.push(t);
	
	long long p;
	while(!qq.empty()){
		fun g=qq.front();
		if(g.a==m){
			return g.s;
		}
		qq.pop();
		for(int i=0;i<2;i++){
			if(i==0){
				p=g.a-1;
			}
			if(i==1){
				p=g.a*2;
			}
			if(b[p]==0&&p>0&&p<=2*m){
			t.a=p;
			t.s=g.s+1;
			b[p]=1;
			qq.push(t);
		   }
		}
	}
}
 
int main(){
	scanf("%d %d",&n,&m);
	if(n>m){
		printf("%d\n",n-m);
		return 0;
	}
	while(!qq.empty()){
		qq.pop();
	}
	long long h=0;
	h+=bfs(n);
	printf("%lld\n",h);
	return 0;
}
