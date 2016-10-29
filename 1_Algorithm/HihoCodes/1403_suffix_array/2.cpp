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
const int MAXM=310;

int cntA[MAXN];
int ranka[MAXN],sa[MAXN];
int cntB[MAXN],rankb[MAXN],sb[MAXN];
int height[MAXN];
int N,K;
int num[MAXN];
int A[MAXN];
int B[MAXN];


void Solve(){
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<=N;i++){
        cntA[num[i]]++;
    }
    for(int i=1;i<MAXM;i++){
        cntA[i]+=cntA[i-1];
    }
    for(int i=N;i>=1;i--){
        sa[cntA[num[i]]--]=i;
    }
    ranka[sa[1]]=1;
    for(int i=2;i<=N;i++){
        ranka[sa[i]]=ranka[sa[i-1]];
        if(num[sa[i]]!=num[sa[i-1]])ranka[sa[i]]++;
    }
    for(int pi=1;ranka[sa[N]]<N;pi*=2){
        memset(cntA,0,sizeof(cntA));
        memset(cntB,0,sizeof(cntB));
        for(int i=1;i<=N;i++){
             A[i]=ranka[i];
             B[i]=i+pi>N?0:ranka[i+pi];
             cntA[A[i]]++;
             cntB[B[i]]++;
        }
        for(int i=1;i<=N;i++){
             cntB[i]+=cntB[i-1];
        }
        for(int i=N;i>=1;i--){
            sb[cntB[B[i]]--]=i;
        }
        for(int i=1;i<=N;i++){
            cntA[i]+=cntA[i-1];
        }
        for(int i=N;i>=1;i--){
            sa[cntA[A[sb[i]]]--]=sb[i];
        }
        ranka[sa[1]]=1;
        for(int i=2;i<=N;i++){
            ranka[sa[i]]=ranka[sa[i-1]];
            if(A[sa[i]]!=A[sa[i-1]]||B[sa[i]]!=B[sa[i-1]]){
                ranka[sa[i]]++;
            }
        }
    }
    for(int i=1,j=0;i<=N;i++){
         if(j)j--;
         while(num[i+j]==num[sa[ranka[i]-1]+j])j++;
         height[ranka[i]]=j;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&K);
    for(int i=1;i<=N;i++){
         scanf("%d",num+i);
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
