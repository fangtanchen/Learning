#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=110;
const int INF=0x7f7f7f7f;
#define DIST(x1,y1,x2,y2) sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2))
int n;
double x[MAXN],y[MAXN];
double G[MAXN][MAXN];
double dist[MAXN];
bool vis[MAXN];

void Init(){
    memset(vis,false,sizeof(vis));
    for(int i=1;i<MAXN;i++){
        dist[i]=INF;
    }
}

double Prim(){
    double ret=0;
    vis[1]=true;
    for(int i=2;i<=n;i++){
        dist[i]=G[1][i];
    }
    do{
        int maxi=-1;
        double maxv=INF;
        for(int i=2;i<=n;i++){
            if(vis[i])continue;
            if(dist[i]<maxv){
                maxv=dist[i];
                maxi=i;
            }
        }
        if(-1==maxi)break;
        ret+=maxv;
        vis[maxi]=true;
        for(int i=2;i<=n;i++){
             if(vis[i])continue;
             if(G[maxi][i]<dist[i]){
                 dist[i]=G[maxi][i];
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
    while(cin>>n){
        Init();
        for(int i=1;i<=n;i++){
            cin>>x[i]>>y[i];
            for(int j=1;j<i;j++){
                 G[i][j]=G[j][i]=DIST(x[i],y[i],x[j],y[j]);
            }
        }
        printf("%.2lf\n",Prim());
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
