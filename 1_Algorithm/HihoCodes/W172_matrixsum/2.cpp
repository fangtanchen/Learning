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
const int MAXN=1010;
const int MAXM=1e5+10;
const int MODU=1e9+7;

int N,M;
int dp[MAXN][MAXN];


void Add(int ri,int ci,int add){
    for(int i=ri;i<=N;i=(i+(i&-i))){
        for(int j=ci;j<=N;j=(j+(j&-j))){
            dp[i][j]=(dp[i][j]+add)%MODU;
            dp[i][j]=(dp[i][j]+MODU)%MODU;
        }
    }
}

int Sum(int ri,int ci){
     int ret=0;
     for(int i=ri;i>0;i=(i^(i&-i))){
         for(int j=ci;j>0;j=(j^(j&-j))){
             ret=(ret+dp[i][j])%MODU;
             ret=(ret+MODU)%MODU;
         }
     }
     return ret;
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    scanf("%d%d",&N,&M);
    for(int mi=0;mi<M;mi++){
         char op[5];
         scanf("%s",op);
         if(strcmp(op,"Add")==0){
             int x,y,add;
             scanf("%d%d%d",&x,&y,&add);
             x++;y++;
             Add(x,y,add);
         }else{
              int x,y,a,b;
              scanf("%d%d%d%d",&x,&y,&a,&b);
              a++,b++;
              int ans=Sum(a,b)+Sum(x,y)-Sum(a,y)-Sum(x,b);
              ans%=MODU;
              ans=(ans+MODU)%MODU;
              printf("%d\n",ans);
         }
    }

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

	return 0;
}
