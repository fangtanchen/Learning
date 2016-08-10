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
const int INF=0x5f5f5f5f;
int map[MAXN][MAXN];
bool vis[MAXN];
int dis[MAXN];
int ans=0;
int N;
int num;

void Init(){
    ans=0;
    num=0;
    memset(map,0,sizeof(map));
    memset(vis,false,sizeof(vis));
    memset(dis,0x5f,sizeof(dis));
}

void Prim(int root){
    dis[root]=0;
    vis[root]=true;
    for(int i=1;i<=N;i++){
        dis[i]=map[root][i];
    }
    do{
        int minv=INF,mini=-1;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            if(dis[i]<minv){
                minv=dis[i];
                mini=i;
            }
        }
        if(mini==-1)break;
        vis[mini]=true;
        ans+=minv;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            int tmp=dis[mini]+map[mini][i];
            if(tmp<dis[i])dis[i]=tmp;
        }
    }while(1);

}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    cin>>N;
    for(int ri=1;ri<=N;ri++){
        for(int ci=1;ci<=N;ci++){
            cin>>map[ri][ci];
        }
    }
    Prim(1);
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
