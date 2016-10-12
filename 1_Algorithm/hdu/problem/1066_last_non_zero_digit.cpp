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


#define MAX 10000000
int dp[MAX];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n;

        int  ans=1;
        int cnt2=0,cnt5=0;
        dp[0]=dp[1]=1;
        for(int i=2;i<MAX;i++){
          int temp=i;
          while(0==temp%2){
              cnt2++;
              temp/=2;
          }
          while(0==temp%5){
               cnt5++;
               temp/=5;
          }
          ans*=temp;
          ans%=10;
          cnt2-=cnt5;
          cnt5=0;
          while(cnt2>10){
               ans*=2;
               ans%=10;
               cnt2--;
          }
          dp[i]=ans;
            for(int j=0;j<cnt2;j++){
                dp[i]*=2;
                dp[i]%=10;
            }
        }
    while(EOF!=scanf("%d",&n)){
        printf("%d\n",dp[n]);
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
