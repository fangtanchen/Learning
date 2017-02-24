#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=3e6+10;

double sum[MAXN];
int T,A;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    sum[0]=-1;
    sum[1]=0;
    for(int i=2;i<MAXN;i++){
        sum[i]=sum[i-1]+log2(i);
    }
    for(int i=2;i<MAXN;i++){
        sum[i]/=i;
    }
    scanf("%d",&T);
    while(T--){
         scanf("%d",&A);
         double tmp=log2(A);
         int l=0,r=MAXN;
         while(l+1<r){
             int mid=(l+r) /2;
             if(sum[mid]<tmp){
                 l=mid;
             }else{
                  r=mid;
             }
         }
         printf("%d\n",r);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
