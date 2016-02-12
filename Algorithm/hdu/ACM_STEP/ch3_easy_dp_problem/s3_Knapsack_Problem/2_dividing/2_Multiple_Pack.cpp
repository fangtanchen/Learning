#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

#define L_JUDGE
#define U_DEBUG

int dp[65000];
int val[20010];
int main(){
	
#ifdef L_JUDGE
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int casei=1;
	int num[7];
	while(EOF!=scanf("%d%d%d%d%d%d",&num[1],&num[2],
					&num[3],&num[4],&num[5],&num[6]),
				num[1]+num[2]+num[3]+num[4]+num[5]+num[6]){
		printf("Collection #%d:\n",casei++);
		memset(dp,0,sizeof(dp));
		memset(val,0,sizeof(val));
		int vali=0;
		int sum=0;
		for(int i=1;i<7;i++){
			sum+=i*num[i];
			int jmax=num[i];
			for(int j=1;j<=jmax;j<<=1){
				val[vali]=j*i;
				vali++;
				jmax=jmax-j;
			}
			if(jmax>0){
				val[vali]=jmax*i;
				vali++;
			}	
		}
		if(sum%2){
			printf("Can't be divided.\n\n");
			continue;
		}
		int half=sum/2;
		for(int i=0;i<vali;i++){
			for(int j=half;j>=val[i];j--){
				int temp=dp[j-val[i]]+val[i];
				if(temp>dp[j]){
					dp[j]=temp;
				}
			}
		}
		if(half==dp[half]){
			printf("Can be divided.\n\n");
		}else{
			printf("Can't be divided.\n\n");
		}

	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
#endif

	return 0;
}
