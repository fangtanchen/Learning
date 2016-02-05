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

int dp[130000];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n[7];
	int casei=1;
	while(EOF!=scanf("%d%d%d%d%d%d",&n[1],&n[2],&n[3],&n[4],&n[5],&n[6]),
				n[1]||n[2]||n[3]||n[4]||n[5]||n[6]){
		printf("Collection #%d:\n",casei++);

		int sum=0;
		for(int i=1;i<=6;i++){
			sum=sum+i*n[i];
		}
		int half=sum/2;
		memset(dp,0,sizeof(dp));
		int flag=0;
		for(int i=1;i<=6;i++){
			if(flag)break;
			for(int ni=n[i];ni>0;ni--){
				if(flag)break;
				for(int j=half;j>=i;j--){
					int temp=dp[j-i]+i;
					if(temp>dp[j])dp[j]=temp;
					if(temp==half){
						flag=1;
						break;
					}
				}
			}
		}
		if(flag){
			printf("Can be divided.");
		}else{
			printf("Can't be divided.");
		}
		printf("\n\n");
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
