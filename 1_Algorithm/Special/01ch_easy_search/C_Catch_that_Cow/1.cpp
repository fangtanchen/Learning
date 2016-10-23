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
const int MAXN=100005;
const int dir[2]={-1,1};

int N,K;
queue<int> qe;
int ans[MAXN];

bool InMap(int x){
    return (x>=0)&&(x<MAXN);
}

void BFS(int st,int ed){
    while(!qe.empty())qe.pop();
    qe.push(st);
    ans[st]=0;
    while(!qe.empty()){
        int now=qe.front();
        qe.pop();
        if(now==ed)break;
        for(int i=0;i<2;i++){
            int nex=now+dir[i];
            if((InMap(nex))&&(ans[nex]==-1)){
                qe.push(nex);
                ans[nex]=ans[now]+1;
            }
        }
        int nex=now*2;
        if((InMap(nex))&&(ans[nex]==-1)){
           qe.push(nex) ;
           ans[nex]=ans[now]+1;
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(2==scanf("%d%d",&N,&K)){
             memset(ans,-1,sizeof(ans));
             BFS(N,K);
             printf("%d\n",ans[K]);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
