#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


class CThing{
	public:
		int P;
		int Q;
		int V;
};
int dp[5200];
CThing prods[550];

int cmp(CThing x, CThing y){
	if(x.Q-x.P>=y.Q-y.P)return false;
	else{
		return true;
	}

}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int N,M;
	while(EOF!=scanf("%d%d",&N,&M)){
		for(int ni=1;ni<=N;ni++){
			scanf("%d%d%d",&prods[ni].P,&prods[ni].Q,&prods[ni].V);
		}
		
		memset(dp,0,sizeof(dp));
		sort(prods+1,prods+1+N,cmp);

#ifdef U_DEBUG
printf("test sort:\n\n");
for(int ni=1;ni<=N;ni++){
	printf("%d %d %d\n",prods[ni].P,prods[ni].Q,prods[ni].V);
}
printf("\n\n");
#endif

		for(int ni=1;ni<=N;ni++){
			for(int mi=M;mi>=prods[ni].Q;mi--){
				int temp=dp[mi-prods[ni].P]+prods[ni].V;
				if(temp>dp[mi])dp[mi]=temp;
			}
		}
		printf("%d\n",dp[M]);
#ifdef U_DEBUG
for(int mi=0;mi<=M;mi++){
	printf("%d ",dp[mi]);
}
printf("\n");
#endif
	}



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
