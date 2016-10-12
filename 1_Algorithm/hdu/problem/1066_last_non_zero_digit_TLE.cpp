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


#define MAX 1000000
int dp[MAX];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n;

    while(EOF!=scanf("%d",&n)){
        long long int  ans=1;
        int cnt2=0,cnt5=0;
        for(int i=2;i<=n;i++){
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
        }
        int pt=cnt2<cnt5?5:2;
        int cnt=cnt2-cnt5;
        if(cnt<0)cnt=cnt*(-1);
        for(int i=0;i<cnt;i++){
            ans*=pt;
            ans%=10;
        }
        printf("%d\n",ans);
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
