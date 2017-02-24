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
const int MAXN=1e5+20;
const char p[2]={'S','W'};

char cmd[MAXN],ans[MAXN];
int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    scanf("%s",cmd+1);
    cmd[N+1]=cmd[1];
    for(int k=0;k<4;k++){
         ans[N+1]=ans[1]=k%2;
         ans[N+2]=ans[2]=k/2;
         for(int i=1;i<=N;i++){
             if(ans[i+1]==0){
                 if(cmd[i+1]=='o')ans[i+2]=ans[i];
                 else ans[i+2]=1-ans[i];
             }else{
                 if(cmd[i+1]=='o')ans[i+2]=1-ans[i];
                 else ans[i+2]=ans[i];
             }
         }
         if((ans[N+1]==ans[1])&&(ans[N+2]==ans[2])){
             for(int i=1;i<=N;i++){
                 putchar(p[ans[i]]);
             }
             putchar('\n');
             return 0;
         }
    }
    puts("-1");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
