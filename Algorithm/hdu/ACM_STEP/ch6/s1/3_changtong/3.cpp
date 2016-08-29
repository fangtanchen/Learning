#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1010;
int N,M;
int fa[MAXN];
int pp[MAXN];
int fi;

int Find(int x){
    int fx=fa[x];
    if(fx==x)return x;
    fa[x]=Find(fx);
    return fa[x];
}

void Union(int x,int y){
     int fx=Find(x),fy=Find(y);
     if(fx==fy)return ;
     else fa[fx]=fy;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N,N){
        for(int i=1;i<=N;i++){
             fa[i]=i;
        }
         cin>>M;
         int a,b;
         while(M--){
              cin>>a>>b;
              Union(a,b);
         }
         memset(pp,0,sizeof(pp));
         for(int i=1;i<=N;i++){
             pp[Find(i)]=1;
         }
         int ans=-1;
         for(int i=1;i<=N;i++){
             ans+=pp[i];
         }
         cout<<ans<<endl;

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
