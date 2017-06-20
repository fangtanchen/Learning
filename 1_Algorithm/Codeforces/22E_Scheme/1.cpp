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
const int MAXN=1e5+10;

int fwd[MAXN],pre[MAXN],vis[MAXN],ind[MAXN];
int tot,cir[MAXN],ker[MAXN],lef[MAXN],usd[MAXN];
int cnt,reu[MAXN],rev[MAXN];

void DFS(int u,int fa){
    if(vis[u]){
        if(!cir[u]){
            ker[++tot]=u;
            cir[u]=tot;
        }
        return;
    }
    pre[u]=fa;
    vis[u]=1;
    DFS(fwd[u],u);
    cir[u]=cir[fwd[u]];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
         scanf("%d",fwd+i);
         ind[fwd[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            DFS(i,0);
        }
    }
    for(int i=1;i<=n;i++){
        if(!ind[i]){
            lef[cir[i]]=i;
        }
    }
    for(int i=1;i<=tot;i++){
        if(!lef[i]){
            lef[i]=ker[i];
        }else{
            usd[lef[i]]=1;
        }
    }
    for(int i=1,j=2;i<=tot;i++,j++){
         if(j>tot)j=1;
         if(ker[i]!=lef[j]){
             cnt++;
             reu[cnt]=ker[i];
             rev[cnt]=lef[j];
         }
    }
    for(int i=1;i<=n;i++){
        if(!ind[i]&&!usd[i]){
            cnt++;
            reu[cnt]=ker[1];
            rev[cnt]=i;
        }
    }
    printf("%d\n",cnt);
    for(int i=1;i<=cnt;i++){
         printf("%d %d\n",reu[i],rev[i]);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
