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
const int MAXN=1e5+10;
const int MAXS=1025;

int cntA[MAXN],cntB[MAXN];
int A[MAXN],B[MAXN];
int rankl[MAXN],sa[MAXN],tsa[MAXN],height[MAXN];
int ch[MAXN];

int N;

void SuffixArray(){
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<=N;i++){
        cntA[ch[i]]++;
    }
    for(int i=1;i<=N;i++){
        cntA[i]+=cntA[i-1];
    }
    for(int i=N;i>=1;i--){
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
             B[i]=(i+l<=N?rankl[i+l]:0);
             cntA[A[i]]++;
             cntB[B[i]]++;
         }
         for(int i=1;i<=N;i++){
              cntB[i]+=cntB[i-1];
         }
         for(int i=N;i>=1;i--){
             tsa[cntB[B[i]]--]=i;
         }
         for(int i=1;i<=N;i++){
              cntA[i]+=cntA[i-1];
         }
         for(int i=N;i>=1;i--){
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

bool Check(int K){
    int minsa,maxsa;
    for(int i=1;i<=N;i++){
        if(height[i]<K){
            minsa=sa[i];
            maxsa=sa[i];
        }else{
             minsa=min(minsa,sa[i]);
             maxsa=max(maxsa,sa[i]);
             if(maxsa-minsa>=K)return true;
        }
    }
    return false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ni=1;ni<=N;ni++){
        scanf("%d",ch+ni);
    }
    SuffixArray();
    int l=0,r=N+1;
    while(l<=r){
         int mid=(l+r)/2;
         if(Check(mid)){
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
