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

#define MAXN 15010
#define MAXX 32010

int tree[MAXX];
int N;
int dp[MAXN];

int lowbit(int k){
    return k&-k;
    //return k&(k^(k-1));
}

int add(int k,int a){
    while(k<=MAXX){
        tree[k]+=a;
        k+=lowbit(k);
    }
    return 0;
}

int query(int k){
     int sum=0;
     while(k>0){
         sum+=tree[k];
         k-=lowbit(k);
     }
     return sum;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d",&N)){
            memset(tree,0,sizeof(tree));
            memset(dp,0,sizeof(dp));
             int x,y;
             for(int ni=1;ni<=N;ni++){
                 scanf("%d%d",&x,&y);
                 x++;
                 dp[query(x)]++;
                 add(x,1);
             }
             for(int ni=0;ni<N;ni++){
                  printf("%d\n",dp[ni]);

             }

        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
