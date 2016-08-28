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
const int MAXN=105;
const int INF=0x7f7f7f7f;
int map[MAXN][MAXN];
bool vis[MAXN];
int dis[MAXN];
int N;

void Init(){
    memset(vis,false,sizeof(vis));
    memset(dis,0x7f,sizeof(dis));
}

int Prim(){
    vis[1]=true;
    int ret=0;
    for(int i=1;i<=N;i++){
        if(!vis[i]){
            dis[i]=map[1][i];
        }
    }
    do{
        int maxi=-1;
        int maxv=INF;
        for(int i=1;i<=N;i++){
            if(!vis[i]) {
                if(dis[i]<maxv){
                    maxi=i;
                    maxv=dis[i];
                }
            }
        }
        if(maxi==-1)break;
        vis[maxi]=true;
        ret+=maxv;
        for(int i=1;i<=N;i++){
             if(vis[i])continue;
             if(map[maxi][i]<dis[i]){
                 dis[i]=map[maxi][i];
             }
        }
    }while(1);
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N,N){
        Init();
        for(int i=N*(N-1)/2;i>=1;i--){
            int a,b,l;
            cin>>a>>b>>l;
            map[a][b]=map[b][a]=l;
        }
        cout<<Prim()<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
