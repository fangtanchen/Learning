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
const int MAXN=2e4+10;
const int MAXM=110;

int ch[MAXN];
int sa[MAXN],tsa[MAXN],rankl[MAXN];
int A[MAXN],B[MAXN];
int cntA[MAXN],cntB[MAXN];
int height[MAXN];
int N,K;

void Solve(){
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<=N;i++){
        cntA[ch[i]]++;
    }
    for(int i=1;i<MAXM;i++){
        cntA[i]+=cntA[i-1];
    }
    for(int i=N;i;i--){
        sa[cntA[ch[i]]--]=i;
    }
    rankl[sa[1]]=1;
    for(int i=2;i<=N;i++){
        rankl[sa[i]]=rankl[sa[i-1]];
        if(ch[sa[i]]!=ch[sa[i-1]])rankl[sa[i]]++;
    }
    for(int l=1;rankl[sa[N]]<N;l*=2){
        memset(cntA,0,sizeof(cntA));
        memset(cntB,0,sizeof(cntB));
        for(int i=1;i<=N;i++){
             A[i]=rankl[i];
             B[i]=i+l<=N?rankl[i+l]:0;
             cntA[A[i]]++;
             cntB[B[i]]++;
        }
        for(int i=1;i<=N;i++){
            cntB[i]+=cntB[i-1];
        }
        for(int i=N;i;i--){
             tsa[cntB[B[i]]--]=i;
        }
        for(int i=1;i<=N;i++){
             cntA[i]+=cntA[i-1];
        }
        for(int i=N;i;i--){
            sa[cntA[A[tsa[i]]]--]=tsa[i];
        }
        rankl[sa[1]]=1;
        for(int i=2;i<=N;i++){
            rankl[sa[i]]=rankl[sa[i-1]];
            if(A[sa[i]]!=A[sa[i-1]]||B[sa[i]]!=B[sa[i-1]]){
                rankl[sa[i]]++;
            }
        }
    }
    for(int i=1,j=0;i<=N;i++){
        if(j)j--;
        while(ch[i+j]==ch[sa[rankl[i]-1]+j])j++;
        height[rankl[i]]=j;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++){
         scanf("%d",ch+i);
    }
    Solve();
    int l=0,r=N+1;
    while(l<=r){
         int mid=(l+r)/2;
         int cnt=1;
         for(int i=1;i<=N;i++){
             if(height[i]>=mid)cnt++;
             else cnt=1;
             if(cnt>=K)break;
         }
         if(cnt>=K){
             l=mid+1;
         }else{
             r=mid-1;
         }
    }
    printf("%d\n",l-1);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
