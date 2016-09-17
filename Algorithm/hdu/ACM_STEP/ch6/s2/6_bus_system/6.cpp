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
typedef long long int ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const int MAXN=110;
const int MAXM=510;

int L[4],C[4];
int map[MAXN][MAXN];
ll cost[MAXN][MAXN];
int N,M;


ll CalcCost(int dist){
    if(dist==0)return 0;
    for(int i=0;i<4;i++){
        if(dist<=L[i]){
            return C[i];
        }
    }
    return INF;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    int cases;
    cin>>cases;
    for(int casei=1;casei<=cases;casei++){
        cout<<"Case "<<casei<<":"<<endl;
        for(int i=0;i<4;i++){
            cin>>L[i];
        }
        for(int i=0;i<4;i++){
            cin>>C[i];
        }
        cin>>N>>M;
        for(int i=1;i<=N;i++){
             cin>>map[i][0];
        }
        for(int i=1;i<=N;i++){
            map[i][i]=0;
            cost[i][i]=0;
            for(int j=i+1;j<=N;j++){
                map[i][j]=map[j][i]=abs(map[i][0]-map[j][0]);
                cost[i][j]=cost[j][i]=CalcCost(map[i][j]);
            }
        }
        for(int k=1;k<=N;k++){
            for(int i=1;i<=N;i++){
                if(i==k)continue;
                for(int j=1;j<=N;j++){
                    if(j==k||i==j)continue;
                    ll tmp=cost[i][k]+cost[k][j];
                    if(tmp<cost[i][j]){
                         cost[i][j]=tmp;
                    }
                }
            }
        }
        for(int i=0;i<M;i++){
             int a,b;
             cin>>a>>b;
             if(cost[a][b]==INF)cout<<"Station "<<a<<" and station "<<b<<" are not attainable."<<endl;
             else cout<<"The minimum cost between station "<<a<<" and station "<<b<<" is "<<cost[a][b]<<"."<<endl;
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		//system("out.txt");
	#endif

	return 0;
}
