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

int Fib[20];
int sg[MAXN];
bool vis[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Fib[0]=Fib[1]=1;
    for(int i=2;i<30;i++){
         Fib[i]=Fib[i-1]+Fib[i-2];
     //    printf("%d %d\n",i,Fib[i]);
    }
    for(int i=0;i<MAXN;i++){
         sg[i]=i;
         memset(vis,true,sizeof(vis));
         for(int j=1;Fib[j]<=i;j++){
             vis[sg[i-Fib[j]]]=false;
         }
         for(int j=0;j<i;j++){
             if(vis[j]){
                  sg[i]=j;
                  break;
             }
         }

    }
    int m,n,p;
    while(scanf("%d%d%d",&m,&n,&p),m|n|p){
        if((sg[m]^sg[n]^sg[p])){
            puts("Fibo");
        }else{
            puts("Nacci");
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
