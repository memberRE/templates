#include<cstdio>
#include<cstring>
#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
#include<cstdlib>
#include<queue>
#define maxn 3000
#define PB(a)   push_back(a)
using namespace std;
deque<char>ans;
vector<int >son[102];
int n,in[maxn],checked[maxn],vis[maxn][maxn];
struct cur_word{
    int a,b,nu;
    bool operator<(const cur_word r)const{
        return a==r.a?b<=r.b:a<=r.a;
    }
}word[2*maxn];
void dfs(int u,int deep){
    ans.push_back(u+'A');
    if(deep==n+1){
        int gg=0;
        while(!ans.empty()){
            char x=ans.front();
            printf("%c",x);
            ans.pop_front();
        }
        exit(0);
    }
    for(int i=0;i<son[u].size();i++){
        int y=son[u][i];
        if(!vis[u][y]&&!vis[y][u]){
            vis[u][y]=1;
            dfs(y,deep+1);
            vis[u][y]=0;
        }
    }
    ans.pop_back();
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        char s[3];
        scanf("%s",s);
        int a=s[0]-'A',b=s[1]-'A';
        in[b]++,in[a]++;
        word[i].a=a,word[i].b=b;
        word[i+n].a=b,word[i+n].b=a;
    }
    sort(word+1,word+2*n+1);
    int ccnt=0,start2=-1,start0=-1;
    for(int i=1;i<=2*n;i++){
        int x=word[i].a ,y=word[i].b;
        son[x].PB(y);
        son[y].PB(x);
        if((in[x])%2&&!checked[x]){
            checked[x]=1,ccnt++;
            if(start0==-1)start0=x;
        }
        if(in[x]==2&&start2==-1)start2=x;
    }
    if(ccnt!=0&&ccnt!=2){
        printf("No Solution");
        exit(0);
    }
    if(ccnt==2)dfs(start0,1);
    if(ccnt ==0)dfs(start2,1);
    return 0;
}