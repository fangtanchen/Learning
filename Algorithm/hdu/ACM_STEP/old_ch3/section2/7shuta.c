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
  int dp[100][100];
  int num[100];

  while(C--){
    memset(dp,sizeof(dp),0);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
      for(int j=0;j<=i;j++){
	scanf("%d",&num[i][j]);
      }
    }
    dp[0][0]=num[0][0];
    for(i=1;i<n;i++){
      dp[i][0]=dp[i-1][0]+num[i][0];
      for(j=1;j<i;j++){
	dp[i][j]=max(dp[i-1][j-1],dp[i-1][j])+num[i][j];
      }
      dp[i][i]=dp[i-1][i-1]+num[i][i];
    }
    int max=dp[n-1][0];
    for(int i=1;i<n;i++){
      if(dp[n-1][i]>max)max=dp[n-1][i];
    }
    printf("%d\n",max);
  }

  return 0;
}
