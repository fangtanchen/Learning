#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef pair<int,int> pii;
const int MAXN=1e5+10;

bool isPrime[MAXN];
int primeList[MAXN],pcnt;
bool vis[MAXN];
vector<pii > G;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N;
    cin>>N;
    int imax=N/2;
    memset(isPrime,true,sizeof(isPrime));
    pcnt=0;
    for(int i=2;i<=imax;i++){
        if(isPrime[i]){
            primeList[pcnt++]=i;
        }
        for(int pi=0;pi<pcnt;pi++){
            int tmp=i*primeList[pi];
            if(tmp>imax)break;
            isPrime[tmp]=false;
            if(i%primeList[pi]==0)break;
        }
    }
    memset(vis,false,sizeof(vis));
    int ans=0;
    for(int pi=pcnt-1;pi>=0;pi--){
        int cnt=0;
        int now=primeList[pi];
        if(!vis[primeList[pi]])
        {
            vis[primeList[pi]]=true;
            cnt=1;
        }
        for(int j=3*primeList[pi];j<=N;j+=primeList[pi]){
            if(vis[j])continue;
            vis[j]=true;
            cnt++;
            if(0==(1&cnt)){
                 G.push_back(make_pair(now,j));
            }else{
                now=j;
            }
        }
        if(1&cnt){
             vis[primeList[pi]*2]=true;
             cnt++;
             G.push_back(make_pair(now,2*primeList[pi]));
        }
        ans+=(cnt/2);
    }
    printf("%d\n",ans);
    for(int i=0;i<G.size();i++)
        printf("%d %d\n",G[i].first,G[i].second);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
