#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=10010;
const int MAXM=40010;

int T,N,M;
int color[MAXN];
vector<int> G[MAXN];

void Init(){
    memset(color,-1,sizeof(color));
    for(int i=0;i<MAXN;i++){
         G[i].clear();
    }
}

bool BFS(int rt){
    queue<int> qe;
    qe.push(rt);
    color[rt]=0;

    while(!qe.empty()){
        int np=qe.front();
        qe.pop();
        for(int i=G[np].size()-1;i>=0;i--){
            int nb=G[np][i];
            if(color[nb]==-1){
                 color[nb]=1-color[np];
                 qe.push(nb);
            }else{
                if(color[nb]==color[np]){
                    return false;
                }
            }
        }
    }
    return true;

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>T;
    while(T--){
         cin>>N>>M;
         Init();
         for(int i=0;i<M;i++){
             int a,b;
             cin>>a>>b;
             G[a].push_back(b);
             G[b].push_back(a);
         }
         bool flag=true;
         for(int i=1;i<=N;i++){
             if(color[i]==-1){
                 flag=BFS(i);
                 if(!flag)break;
             }
         }
         if(flag){
              printf("Correct\n");
         }else{
             printf("Wrong\n");
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
