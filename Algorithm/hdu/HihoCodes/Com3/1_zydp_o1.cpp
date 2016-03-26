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

const int HS=2187;
const int S=1594323;
const int HJ=1<<7;
int modu[15];

int trans[HS][HJ][2];
typedef long long ll;
ll dp[2][S][2];


void pre(){
    modu[0]=1;
    for(int i=1;i<13;i++)
        modu[i]=modu[i-1]*3;
    for(int i=0;i<HS;i++){
        for(int j=0;j<HJ;j++){
            for(int k=0;k<2;k++){
                int newi=i;
                for(int hu=0;hu<7;hu++){
                    int temp=i/modu[hu]%3;
                    if(j>>hu&1){
                        if(2!=temp) {
                            newi+=(temp?-modu[hu]:modu[hu]);
                        }
                    }else{
                        if(2==temp){
                            newi=newi-(2-k)*modu[hu];
                        }
                    }

                }
                trans[i][j][k]=newi;
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    pre();
    int n;
    scanf("%d",&n);
    int a;
    int di=0;
    dp[di][S-1][0]=1;
    for(int ni=0;ni<n;ni++){
         scanf("%d",&a);
         int ah=a/(HJ);
         int al=a%HJ;
         memset(dp[1-di],0,sizeof(dp[1-di]));
         for(int j=0;j<S;j++){
             int jh=j/HS;
             int jl=j%HS;
             for(int k=0;k<2;k++){
                 if(!dp[di][j][k])continue;
                 dp[1-di][j][k]+=dp[di][j][k];
                 int t1=trans[jh][ah][k]*HS;
                 int temp=t1+trans[jl][al][k];
                 dp[1-di][temp][1-k]+=dp[di][j][k];
             }
         }
         di=1-di;
    }
    ll cnt=0;
    for(int j=0;j<S;j++){
        for(int k=0;k<2;k++){
            if(!dp[di][j][k])continue;
            int flag=1;
            for(int hu=0;hu<13;hu++){
                 int temp=j/modu[hu]%3;
                 if(temp==1||((temp==2)&&(0==k))){
                     flag=0;
                     break;
                 }
            }
            if(flag)cnt+=dp[di][j][k];
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
