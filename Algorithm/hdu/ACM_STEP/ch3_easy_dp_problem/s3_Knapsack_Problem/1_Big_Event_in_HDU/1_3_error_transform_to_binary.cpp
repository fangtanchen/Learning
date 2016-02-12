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

int dp[250010];
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int N;
	int value[5050];
	int valuen_len;
	while(EOF!=scanf("%d",&N),N>0){
		int sum=0;
		int value_len=0;
		int temp_value,temp_num;
		memset(dp,0,sizeof(dp));
		for(int i=0;i<N;i++){
			scanf("%d%d",&temp_value, &temp_num);
			sum=sum+temp_value*temp_num;
			int pp=log2(temp_num);
			while(1){
				int tt=pow(2,pp);
#ifdef U_DEBUG
	printf("%d ",tt);
#endif
				value[value_len]=tt*temp_value;
				value_len++;
				temp_num=temp_num-tt;
				if(0==temp_num){
					break;
				}
				pp=log2(temp_num);
			}
#ifdef U_DEBUG
	printf("\n\n\n\n");
#endif
		}
		int aver=(sum)/2;
		for(int i=0;i<value_len;i++){
			for(int j=aver;j>=value[i];j--){
				int temp=dp[j-value[i]]+value[i];
				if(dp[j]<temp){
					dp[j]=temp;
				}
			}
		}
		int pt=dp[aver];
		for(int i=aver-1;i>=0;i--){
			if(pt<dp[i])pt=dp[i];
		}
		printf("%d %d\n",sum-dp[aver],dp[aver]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
