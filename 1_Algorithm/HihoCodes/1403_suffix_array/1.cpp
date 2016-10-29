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
const int MAXK=2e4+10;
const int MAXS=300;

int ch[MAXN];
int cntA[MAXN],cntB[MAXN];
int sa[MAXN],tsa[MAXN];
int A[MAXN],B[MAXN];
int rankl[MAXN];
int height[MAXN];
int N,K;

void SuffixArray(){
    memset(cntA,0,sizeof(cntA));
    for(int i=1;i<=N;i++){
        cntA[ch[i]]++;
    }
    for(int i=1;i<MAXS;i++){
        cntA[i]+=cntA[i-1];
    }
    for(int i=N;i>0;i--){
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
            B[i]=(i+l<=N?rankl[(i+l)]:0);
            cntA[A[i]]++;
            cntB[B[i]]++;
        }
        for(int i=1;i<=N;i++){
             cntB[i]+=cntB[i-1];
        }
        for(int i=N;i>0;i--){
            tsa[cntB[B[i]]--]=i;
        }
        for(int i=1;i<=N;i++){
             cntA[i]+=cntA[i-1];
        }
        for(int i=N;i>0;i--){
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
    for(int i=1,l=0;i<=N;i++){
        if(l)l--;
        while(ch[i+l]==ch[sa[rankl[i]-1]+l])l++;
        height[rankl[i]]=l;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
#endif
        cin.sync_with_stdio(false);
        cin>>N>>K;
        for(int i=1;i<=N;i++){
            cin>>ch[i];
        }
        SuffixArray();
        int l=0,r=N+1;
        while(l<=r){
            int mid=(l+r)>>1;
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
        cout<<l-1<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
