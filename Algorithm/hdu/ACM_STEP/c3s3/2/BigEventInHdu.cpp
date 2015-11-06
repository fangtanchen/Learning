#include <iostream>
#include<cstdio>
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class Program{
public:
	void fun(){
		int dp[250005];
		int N;
		int V[1010],M[1010];
		while(scanf("%d",&N)&&(N>=0)){
			int total=0;
			for(int ni=0;ni<N;ni++){
				cin>>V[ni]>>M[ni];
				total=total+V[ni]*M[ni];
			}
			
			for(int dpi=1;dpi<=total;dpi++)
				dp[dpi]=0;
			dp[0]=1;
			
			for(int ni=0;ni<N;ni++){
				for(int mi=1;mi<=M[ni];mi++){
					int nvalue=V[ni]*mi;
					//int maxValue=total-nvalue;
					for(int valuei=nvalue;valuei<=total;valuei++){
						if(dp[valuei-nvalue]==1)
							dp[valuei]=2;
					}
				}
				
				for(int i=0;i<=total;i++){
					if(dp[i]==2)dp[i]=1;
				}
			}
			int temp=(total+1)/2;
			int A;
			for(A=temp;dp[A]==0;A++);
				
			cout<<A<<" "<<total-A<<endl;
		}
	}	
		
};

int main(int argc, char** argv) {
	Program p;
	p.fun();
	return 0;
}
