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
vector<int> G[MAXN];
queue<int> que;
int fa[MAXN];

void Init(){
    for(int i=1;i<MAXN;i++){
        G[i].clear();
    }
    while(!que.empty()){
        que.pop();
    }
    memset(fa,-1,sizeof(fa));
}

bool BFS(int rt){
    fa[rt]=0;
    que.push(rt);
    while(!que.empty()){
        int k=que.front() ;
        que.pop();
        for(int i=G[k].size()-1;i>=0;i--){
            int nb=G[k][i];
            if(-1==fa[nb]){
                fa[nb]=1-fa[k];
                que.push(nb);
            }else if(fa[nb]==fa[k]){
                return false;
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
        for(int mi=0;mi<M;mi++){
            int a,b;
            cin>>a>>b;
            G[a].push_back(b);
            G[b].push_back(a);
        }
        bool flag=true;
        for(int i=1;i<=N;i++){
            if(fa[i]==-1){
                 flag=BFS(i);
                 if(!flag)break;
            }
        }
        if(flag)cout<<"Correct"<<endl;
        else cout<<"Wrong"<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
