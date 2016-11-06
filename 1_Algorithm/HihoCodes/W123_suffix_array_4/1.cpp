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


char ch[MAXN];
int cntA[MAXN],cntB[MAXN],A[MAXN],B[MAXN];
int rankl[MAXN],sa[MAXN];
int tsa[MAXN];
int height[20][MAXN];
int N;
int fac2[20];

void CreateSuffixArray(){
     memset(cntA,0,sizeof(cntA));
     for(int i=1;ch[i];i++){
         cntA[ch[i]]++;
     }
     for(int i=1;i<=300;i++){
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
     for(int l=1;rankl[sa[N]]<N;l<<=1){
         memset(cntA,0,sizeof(cntA));
         memset(cntB,0,sizeof(cntB));
         for(int i=1;i<=N;i++){
             A[i]=rankl[i];
             B[i]=i+l<=N?rankl[i+l]:0;
             cntA[A[i]]++;
             cntB[B[i]]++;
         }
         for(int i=1;i<=N;i++){
              cntA[i]+=cntA[i-1];
              cntB[i]+=cntB[i-1];
         }
         for(int i=N;i;i--){
             tsa[cntB[B[i]]--]=i;
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

     memset(height,0,sizeof(height));
     for(int i=1,j=0;i<=N;i++){
          if(j)j--;
          while(ch[i+j]==ch[sa[rankl[i]-1]+j])j++;
          height[0][rankl[i]]=j;
     }
     fac2[0]=1;
     for(int si=1;si<20;si++){
         fac2[si]=fac2[si-1]<<1;
         if((fac2[si])>N)break;
         for(int i=N-(fac2[si]);i;i--){
             height[si][i]=min(height[si-1][i],height[si-1][i+fac2[si-1]]);
         }
     }
}

int LCS(int len,int st){
    int l=rankl[st];
    int r=rankl[st+len];
    if(l>r)swap(l,r);
    l=l+1;
    int dist=r-l+1;
    int si=0;
    for(si=0;fac2[si]<=dist;si++)
        ;
    si=si-1;
    return min(height[si][l],height[si][r-fac2[si]+1]);
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    ch[0]='#';
    scanf("%s",ch+1);
    N=strlen(ch)-1;
    CreateSuffixArray();
    int ans=0;
    for(int l=1;l<=N;l++){
        for(int i=1;i+l<=N;i+=l){
            int R=LCS(l,i);
            ans=max(ans,R/l+1);
            if(i>=l-R%l){
                 ans=max(ans,LCS(l,i+R%l-l)/l+1);
            }
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
