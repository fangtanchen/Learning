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

int fib[20];
int cnt[20];
int m[5];
int ans;

void DFS(int di,int n,int fibi){
    if(ans)return;
    if(n==0){
        if(di<3){
            int i=19;
            for(;fib[i]>m[di+1];i--)
                ;
            DFS(di+1,m[di+1],i);
        }else{
            int tmp=0;
            for(int i=1;i<19;i++){
                tmp^=cnt[i];
                if(tmp)ans=1;
            }
        }
        return;
    }
    for(int i=fibi;i>=1;i--){
         if(fib[i]>n)continue;
         cnt[i]++;
         DFS(di,n-fib[i],fibi);
         cnt[i]--;
         if(ans)return;
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    fib[0]=fib[1]=1;
    for(int i=2;i<20;i++)fib[i]=fib[i-1]+fib[i-2];
    while(scanf("%d%d%d",m+1,m+2,m+3),m[3]+m[1]+m[2]){
        int i=19;
        for(;fib[i]>m[1];i--)
            ;
        memset(cnt,0,sizeof(cnt));
        ans=0;
         DFS(1,m[1],i);
         if(ans)printf("Fibo\n");
         else printf("Nacci\n");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
