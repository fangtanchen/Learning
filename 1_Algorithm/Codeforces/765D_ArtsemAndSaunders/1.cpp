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

int f[MAXN],g[MAXN],h[MAXN];
bool vis[MAXN];
int N,M;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%d",f+i);
    }
    bool flag=true;
    for(int i=1;i<=N;i++){
        if(f[f[i]]!=f[i]){
            flag=false;
            break;
        }
    }
    if(!flag)return 0*printf("-1\n");
    M=0;
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=N;i++){
        if(!vis[f[i]]){
            vis[f[i]]=true;
            g[f[i]]=++M;
            h[M]=f[i];
        }
        g[i]=g[f[i]];
    }

    printf("%d\n",M);
    for(int i=1;i<=N;i++){
         printf("%d%c",g[i],(i==N?'\n':' '));
    }

    for(int i=1;i<=M;i++){
         printf("%d%c",h[i],(i==M?'\n':' '));
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
