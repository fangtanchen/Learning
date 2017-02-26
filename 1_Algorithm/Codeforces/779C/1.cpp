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
typedef long long int LL;
const int MAXN=5e5+10;

int diff[MAXN];
int N,K;
int A[MAXN],B[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&K);
    LL sum=0;
    for(int i=0;i<N;i++){
        scanf("%d",&A[i]);
    }
    for(int i=0;i<N;i++){
        scanf("%d",&B[i]);
    }
    for(int i=0;i<N;i++){
        sum+=B[i];
        diff[i]=A[i]-B[i];
    }
    sort(diff,diff+N);
    for(int i=0;i<K;i++){
         sum+=diff[i];
    }
    for(int i=K;i<N;i++){
        if(diff[i]>=0)break;
        sum+=diff[i];
    }

    printf("%lld\n",sum);
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
