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
const int MAXN=1e6+10;
const int MODU=1e9+7;

LL sum[MAXN+1];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    memset(sum,0,sizeof(sum));
    sum[2]=1;
    LL k=1;
    for(int i=2;i<MAXN;i++){
        k=(k+i)%MODU;
        sum[i+1]=(sum[i]+k)%MODU;
    }
    int T;
    scanf("%d",&T);
    while(T--){
         int x,y;
         scanf("%d%d",&x,&y);
         if(x<2)x=2;
         LL ans=(sum[y-1]-sum[x-2]+MODU)%MODU;
         printf("%lld\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
