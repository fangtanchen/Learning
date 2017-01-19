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
const int MAXN=5e4+10;
const int MODU=998244353;

int A[MAXN],N,T;
int ans;

void Sort(int l,int r,int mask){
    if(l==r)return;
    int i=l,j=r;
    while(i<=j){
        while(((A[i]&mask)==0)&&(i<=r))
            i++;
        while((A[j]&mask)&&(j>=l))
            j--;
        if(i>j)break;
        if(i>r)continue;
        if(j<l)continue;
        swap(A[i],A[j]);
    }
    if(j>l){
        Sort(l,j,mask<<1);
    }
    if(i<r){
        Sort(i,r,mask<<1);
    }
    ans=ans+(j-l+1)*(r-i+1);
    ans%=MODU;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){
         scanf("%d",&N);
         for(int i=0;i<N;i++){
             scanf("%d",A+i);
         }
         ans=0;
         Sort(0,N-1,1);
         printf("Case #%d: %d\n",ti,ans);
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
