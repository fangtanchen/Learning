#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+2;
const int MAXM=1005;

int pa[MAXN];
bool in[MAXM];
queue<int> G[MAXM];
queue<int> Q;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int T;
    int si=1;
    while(scanf("%d",&T),T){
        printf("Scenario #%d\n",si++);
        memset(in,false,sizeof(in));
        memset(pa,-1,sizeof(pa));
        for(int i=0;i<MAXM;i++){
            while(!G[i].empty())G[i].pop();
        }
        while(!Q.empty())Q.pop();
        int n,p,x;
        for(int ti=1;ti<=T;ti++){
            scanf("%d",&n);
            for(int k=0;k<n;k++){
                scanf("%d",&p);
                pa[p]=ti;
            }
        }
        char cmd[20];
        while(scanf("%s",cmd),cmd[0]!='S'){
            if(cmd[0]=='E'){
                scanf("%d",&x);
                int px=pa[x];
                G[px].push(x);
                if(!in[px]){
                     in[px]=true;
                     Q.push(px);
                }
            }else{
                int k=Q.front();
                printf("%d\n",G[k].front());
                G[k].pop();
                if(G[k].empty()){
                     Q.pop();
                     in[k]=false;
                }
            }
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
