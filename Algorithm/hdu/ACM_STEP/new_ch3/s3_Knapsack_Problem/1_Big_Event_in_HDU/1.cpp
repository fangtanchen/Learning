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

class CFacility{
public:
	int value;
	int num;
};

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int N;
	CFacility fa[55];
	while(EOF!=scanf("%d",&N),N>=0){
		int sum=0;
		for(int i=0;i<N;i++){
			scanf("%d%d",fa[i].value,fa[i].num);
			sum=sum+fa[i].value*fa[i]*num;
		}
		int aver=(sum+1)/2;
		int dp[55];
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++){
			for(int ni=0;ni<fa[i].num;ni++){
				
			}
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
