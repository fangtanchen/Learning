#include<stdio.h>
#include<string.h>



int max(int x,int y){
  return x>y?x:y;
}

int main()
{
  int C;
  scanf("%d",&C);
  int n;
  int dp[2][100];
  int num[100][100];

  while(C--){
	  int N;
	  scanf("%d",&N);
	  int dpi=0;
	  memset(dp,0,sizeof(dp));

	  for(int i=0;i<N;i++){
		  for(int j=0;j<=i;j++){
			  scanf("%d",&num[i][j]);
		  }
	  }
	  dpi=0;
	  dp[dpi][0]=num[0][0];

	  for(int i=1;i<N;i++){
		  dp[1-dpi][0]=dp[dpi][0]+num[i][0];
		  for(int j=1;j<i;j++){
			  dp[1-dpi][j]=max(dp[dpi][j],dp[dpi][j-1])+num[i][j];
		  }
		  dp[1-dpi][i]=dp[dpi][i-1]+num[i][i];
		  dpi=1-dpi;
	  }
	  int ans=dp[dpi][0];
	  for(int i=1;i<N;i++){
		  ans=(ans<dp[dpi][i]?dp[dpi][i]:ans);
	  }
	  printf("%d\n",ans);
  }

  return 0;
}

