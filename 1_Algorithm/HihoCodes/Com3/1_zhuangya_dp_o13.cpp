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

const int S=1594323;

long long dp[2][S][2];
int modu[14];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    modu[0]=1;
    for(int i=1;i<13;i++)
        modu[i]=modu[i-1]*3;

    int a,n;
    scanf("%d",&n);
    dp[0][S-1][0]=1;
    int di=0;
    for(int i=0;i<n;i++){
         scanf("%d",&a);
         memset(dp[1-di],0,sizeof(dp[1-di]));
         for(int j=0;j<S;j++){
             for(int k=0;k<2;k++){
                 if(dp[di][j][k]==0)continue;
                 int newj=j;
                 for(int hu=0;hu<13;hu++){
                    int temp=j/modu[hu]%3;
                    if((1<<hu)&(a)){
                        if(temp!=2){
                            if(temp==1){
                                newj-=modu[hu];
                            }else{
                                newj+=modu[hu];
                            }
                        }
                    }else{
                        if(2==temp){
                             newj=newj-(2-k)*modu[hu];
                        }
                    }
                 }
                 dp[1-di][j][k]+=dp[di][j][k];
                 dp[1-di][newj][1-k]+=dp[di][j][k];
             }
         }
         di=1-di;
    }
    long long cnt=0;
    for(int j=0;j<S;j++){
        for(int k=0;k<2;k++){
            if(!dp[di][j][k])continue;
            int flag=1;
            for(int hu=0;hu<13;hu++){
                int temp=j/modu[hu]%3;
                if(!((2==temp&&(k==1))||
                        (temp==0))){
                    flag=0;
                    break;
                }
            }
            if(flag){
                 cnt+=dp[di][j][k];
            }
        }
    }
    printf("%lld\n",cnt);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
