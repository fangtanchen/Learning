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


#define MAXN 50004
int val[MAXN];
int dp[MAXN];
int N;


int create(){
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=N;i++){
        int temp=i-i&-i+1;
        while(temp<=i){
            dp[i]+=val[temp];
            temp++;
        }
    }
    return 0;
}
int lowbit(int x){
    return x&-x;
//    return  x&(x^(x-1));
}

int add(int i,int b){
    //val[i]  +=b;
    while(i<=N){
        dp[i]+=b;
        i+=(i&-i);
    }
    return 0;
}

int sub(int i,int b){
     //val[i]-=b;
     while(i<=N){
          dp[i]-=b;
          i+=(i&-i);
     }
     return 0;
}
int query(int i){
     int res=0;
     while(i>0){
         res+=dp[i];
         i-=(i&-i);
     }
     return res;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);

    for(int ti=1;ti<=T;ti++){
         printf("Case %d:\n",ti);
         scanf("%d",&N);
         memset(dp,0,sizeof(dp));
         for(int ni=1;ni<=N;ni++){
             scanf("%d",val+ni);
             add(ni,val[ni]);
         }
        char s[55];
        int a,b;
        while(scanf("%s",s),strcmp("End",s)){
            scanf("%d%d",&a,&b);
            if(!strcmp(s,"Query")){
                printf("%d\n",query(b)-query(a-1));
            }else if(!strcmp(s,"Add")){
                add(a,b);
            }else if(!strcmp(s,"Sub")){
                sub(a,b);
            }
        }

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
