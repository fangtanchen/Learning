#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=2010;
typedef pair<int,int> pii;

pii x[MAXN];
bool vis[MAXN];
int N,T;

bool cmp(pii a,pii b){
    if(a.second>b.second)return true;
    else if(a.second==b.second)
        return a.first>b.first;
    else return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         int ans=0;
         scanf("%d",&N);
         for(int i=1;i<=N;i++){
             scanf("%d",&x[i].first);
         }
         for(int i=1;i<=N;i++){
             scanf("%d",&x[i].second);
         }
         sort(x+1,x+N+1,cmp);
         memset(vis,false,sizeof(vis));
         for(int ni=1;ni<=N;ni++){
              int t=x[ni].first;
              bool flag=false;
              for(;t>0;t--){
                  if(!vis[t]){
                      flag=true;
                      vis[t]=true;
                      break;
                  }
              }
              if(!flag){
                  ans+=x[ni].second;
              }
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
