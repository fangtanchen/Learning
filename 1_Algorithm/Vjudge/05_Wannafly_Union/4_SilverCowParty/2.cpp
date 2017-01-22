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
const int MAXN=1002;
const int INF=0x3f3f3f3f;
const int MODU=MAXN*5;

int dp[MAXN][MAXN];
int N,M,X;
int d1[MAXN],d2[MAXN];
bool vis[MAXN];
int queue[MAXN*5];
int head=0;
int tail=-1;

void Init(){
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<MAXN;i++){
        dp[i][i]=0;
    }
}


int scan(){
    int ch=0;
    while((ch=getchar()),ch<'0'||ch>'9')
        ;
    int ret=ch-'0';
    while((ch=getchar()),ch>=0&&(ch<=9)){
        ret=ret*10+ch-'0';
    }
    return ret;
}

void trans(){
    for(int i=1;i<=N;i++){
        for(int j=1;j<i;j++){
            swap(dp[i][j],dp[j][i]);
        }
    }
}

bool IsEmpty(){
    return (tail+1)%MODU==head;
}

int Top(){
     return queue[head];
}

int Pop(){
    head=(1+head)%MODU;
    return 0;
}
int Push(int x){
    tail=(tail+1)%MODU;
    queue[tail]=x;
    return 0;
}

void SPFA(int *dist){
    memset(dist,0x3f,sizeof(int)*MAXN);
     memset(vis,false,sizeof(vis));
     head=0;
     tail=-1;
     Push(X);
     //for(int i=1;i<=N;i++)dist[i]=dp[X][i];
     dist[X]=0;
     vis[X]=true;
     while(!IsEmpty()){
        int x=Top();
        Pop();
        vis[x]=false;
        for(int i=1;i<=N;i++){
            int tmp=dist[x]+dp[x][i];
            if(tmp<dist[i]){
                dist[i]=tmp;
                if(!vis[i]){
                    vis[i] =true;
                    Push(i);
                }
            }
        }
     }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    while(EOF!=scanf("%d%d%d",&N,&M,&X)){
        Init();
        for(int mi=0;mi<M;mi++){
            int u,v,c;
            scanf("%d%d%d",&u,&v,&c);
            dp[u][v]=min(c,dp[u][v]);
        }
        SPFA(d1);
        trans();
        SPFA(d2);
        int ans=0;
        for(int i=1;i<=N;i++){
            if(d1[i]==INF||d2[i]==INF)continue;
            int tmp=d1[i]+d2[i];
            ans=max(tmp,ans);
        }
        printf("%d\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
