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
const int MAXN=10010;
const int dir[4]={1,10,100,1000};

bool isprime[MAXN];
bool vis[MAXN];

void Init(){
    memset(isprime,true,sizeof(isprime));
    isprime[1]=false;
    int primeList[MAXN];
    int cnt=0;
    for(int i=2;i<MAXN;i++){
        if(isprime[i]){
            primeList[cnt]=i;
            cnt++;
        }
        for(int j=0;j<cnt;j++){
            if(i*primeList[j]>=MAXN)break;
            isprime[i*primeList[j]]=false;
            if(i%primeList[j]==0){
                break;
            }
        }
    }
}

int N,M;
queue<pair<int,int> > qe;

int BFS(int st,int ed){
    while(!qe.empty()){
         qe.pop();
    }
    memset(vis,false,sizeof(vis));
    qe.push(make_pair(st,0));
    vis[st]=true;
    while(!qe.empty()){
        pair<int,int> now=qe.front() ;
        qe.pop();
        if(now.first==ed){
             return now.second;
        }
        for(int di=0;di<4;di++){
            int nex=now.first-(now.first/dir[di])%10*dir[di];
            for(int i=0;i<10;i++){
                int tmp=nex+i*dir[di];
                if((!isprime[tmp])||(vis[tmp])||(tmp<1000))continue;
                vis[tmp]=true;
                qe.push(make_pair(tmp,now.second+1));
            }
        }
    }
    return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int cases;
    scanf("%d",&cases);
    Init();
    while(cases--){
         scanf("%d%d",&N,&M);
         int ret=BFS(N,M);
         if(ret==-1){
              printf("Impossible\n");
         }
         else{
             printf("%d\n",ret);
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
