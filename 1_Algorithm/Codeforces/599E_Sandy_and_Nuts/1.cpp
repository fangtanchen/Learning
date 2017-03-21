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
const int MAXN=13;
const int MAXQ=200;
typedef long long LL;

int N,M,Q;
LL dp[MAXN][1<<MAXN];
int u[MAXN],v[MAXN];
int a[MAXQ],b[MAXQ],c[MAXQ];


void DFS(int rt,int mask){
    if(dp[rt][mask]>=0)return;
    if(__builtin_popcount(mask)==1){
        dp[rt][mask]=1;
        return;
    }
    dp[rt][mask]=0;
    int sup=(mask^(1<<rt)),sub=sup;

    do{
        if((sup&-sup)&sub){
            int tsub=mask^sub;
            DFS(rt,mask^sub);
            for(int i=0;i<N;i++) {
                if(!(sub&(1<<i)))continue;
                bool isok=true;
                for(int j=0;j<M;j++){
                    if(!isok) break;
                    if(((mask&(1<<u[j]))&&(mask&(1<<v[j])))
                    &&(!((sub&(1<<u[j]))&&(sub&(1<<v[j]))))
                    &&(!((tsub&(1<<u[j]))&&(tsub&(1<<v[j]))))
                    &&(!((u[j]==rt)&&(v[j]==i)||((u[j]==i)&&(v[j]==rt)))))
                        isok=false;
                }
                for(int j=0;j<Q;j++){
                     if(!isok)break;
                     if(((mask&(1<<a[j]))&&(mask&(1<<b[j]))&&(mask&(1<<c[j])))
                     &&(!((sub&(1<<a[j]))&&(sub&(1<<b[j]))&&(sub&(1<<c[j]))))
                     &&(!((tsub&(1<<a[j]))&&(tsub&(1<<b[j]))&&(tsub&(1<<c[j]))))
                     &&(!((rt==c[j])&&(((sub&(1<<a[j]))&&(tsub&(1<<b[j])))
                    ||((sub&(1<<b[j]))&&(tsub&(1<<a[j])))))))
                         isok=false;
                }
                if(!isok)continue;
                DFS(i,sub);
                dp[rt][mask]+=(dp[i][sub]*dp[rt][tsub]);
            }
        }
        sub=(sub-1)&sup;
    }while(sub!=sup);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M>>Q;
    for(int i=0;i<M;i++){
         cin>>u[i]>>v[i];
         u[i]--;v[i]--;
    }
    for(int i=0;i<Q;i++){
         cin>>a[i]>>b[i]>>c[i];
         a[i]--;b[i]--;c[i]--;
    }
    memset(dp,-1,sizeof(dp));
    DFS(0,(1<<N)-1);
    printf("%lld\n",dp[0][(1<<N)-1]);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
