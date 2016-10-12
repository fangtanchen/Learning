#include <iostream>
#include<algorithm>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Coin{
	int W;
	int P;
};
struct Coin coins[510];

int dp[10010];
const int MAXN=550;
const int INF=0x3f3f3f3f;

int cmp(struct Coin x, struct Coin y){
	if(x.W>y.W)return 0;
	else if((x.W==y.W)&&(x.P>y.P))return 0;
	return 1;
}


int min(int x, int y )
{
	return (x>y?y:x);
}

int main(int argc, char** argv) {
	int T;
	cin>>T;
	for(int Ti=0;Ti<T;Ti++){
		int E,F;
		cin>>E>>F;
		int N;
		cin>>N;
		for(int Ni=0;Ni<N;Ni++){
			cin>>coins[Ni].P>>coins[Ni].W;
		}
		
		int totalWeight=F-E;
		for(int i=0;i<=totalWeight;i++) dp[i]=INF;
		dp[0]=0;
		/*for(int Ni=0;Ni<N;Ni++){
			for(int j=coins[Ni].W;j<=totalWeight;j++){
				if(dp[j-coins[Ni].W]<INF)
					dp[j]=min(dp[j-coins[Ni].W]+coins[Ni].P,dp[j]);
			}
		}
		*/
		for(int Ni=0;Ni<N;Ni++){
			for(int j=coins[Ni].W;j<=totalWeight;j++){
				if(dp[j-coins[Ni].W]<INF)
					dp[j]=min(dp[j-coins[Ni].W]+coins[Ni].P,dp[j]);
			}
		}
		
		if(dp[totalWeight]==INF)cout<<"This is impossible."<<endl;
		else cout<<"The minimum amount of money in the piggy-bank is "<<dp[totalWeight]<<"."<<endl;
		
	}
	return 0;
}
