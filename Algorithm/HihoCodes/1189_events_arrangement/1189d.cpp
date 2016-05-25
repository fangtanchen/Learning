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

struct CEvent{
     int a;
     int b;
     int c;
     void Input(){
         scanf("%d%d%d",&a,&b,&c);
     }
};

#define MAXN 1024
#define MAXM 5010
#define MANK 1024

CEvent e[MAXN];
int dp[2][MAXM];
int q[MAXM][MAXN];
int head[MAXM];
int tail[MAXM];

int cmp(CEvent x,CEvent y){
    return x.b*y.c>y.b*x.c;
}

int calc(int i,int st,int ed){
    int k=(ed-st)/e[i].c;
    return k*(e[i].a-st*e[i].b)-k*(k-1)/2*e[i].b*e[i].c;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);
    for(int i=0;i<N;i++){
        e[i].Input();
    }
    sort(e,e+N,cmp);
    int si=0;
    int di=1;
    memset(dp,0,sizeof(dp));
    memset(q,0,sizeof(q));
    for(int ni=0;ni<N;ni++){
         memset(tail,0,sizeof(tail));
         for(int i=0;i<5001;i++){
             head[i]=1;
         }
         int c=e[ni].c;
        for(int vi=0;vi<M;vi++){
            int r=vi%c;
            tail[r]++;
            q[r][tail[r]]=vi;

            int val1=dp[si][q[r][tail[r]]];//+calc(ni,q[r][tail[r]],vi);

            while(tail[r]>head[r]){
                 int tempval2=calc(ni,q[r][tail[r]-1],vi);
                 int val2=tempval2+dp[si][q[r][tail[r]-1]];
                 if(val1>=val2){
                     q[r][tail[r]-1]=q[r][tail[r]];
                     tail[r]--;
                 }else{
                      break;
                 }
            }
            while((vi-q[r][head[r]])/c>K){
                 head[r]++;
             }
             dp[di][vi]=dp[si][q[r][head[r]]]+calc(ni,q[r][head[r]],vi);
        }
        si=1-si;
        di=1-di;
    }
    int ans=0;
    for(int i=0;i<M;i++){
        if(dp[si][i]>ans)ans=dp[si][i];
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
