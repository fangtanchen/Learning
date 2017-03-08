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
const int MAXN=1005;
const int MAXM=5e5+20;

int A[MAXN];
int T,N,M;
int pa[MAXN];
bool vis[MAXN];
int ans[MAXN],anscnt;

int Find(int x){
     if(x==pa[x])return x;
     pa[x]=Find(pa[x]);
     return pa[x];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>T;
    for(int ti=1;ti<=T;ti++){
        cin>>N>>M;
        for(int i=1;i<=N;i++){
            pa[i]=i;
            cin>>A[i];
        }
        for(int mi=0;mi<M;mi++){
             int u,v;
             cin>>u>>v;
             int fu=Find(u),fv=Find(v);
             int minu=min(fu,fv),maxu=max(fu,fv);
             if(maxu!=minu)
                 A[minu]+=A[maxu],pa[maxu]=minu;
        }
        memset(vis,false,sizeof(vis));
        anscnt=0;
        for(int i=1;i<=N;i++){
             int f=Find(i);
             if(!vis[f]){
                 vis[f]=true;
                 ans[anscnt]=A[f];
                 anscnt++;
             }
        }
        sort(ans,ans+anscnt);
        printf("Case %d: %d\n",ti,anscnt);
        printf("%d",ans[0]);
        for(int i=1;i<anscnt;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
