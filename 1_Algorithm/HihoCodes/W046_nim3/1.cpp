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
const int MAXN=0x8000;

int sg[MAXN];
bool vis[MAXN];
int A[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    int maxi=0;
    for(int i=1;i<=N;i++){
         scanf("%d",A+i);
         if(A[i]>maxi)maxi=A[i];
    }
    sg[0]=0;
    for(int i=1;i<=maxi;i++){
        memset(vis,0,sizeof(vis));
        vis[sg[0]]=true;
        for(int j=1;j<i;j++){
             vis[sg[j]]=true;
             vis[sg[j]^sg[i-j]]=true;
        }
        for(int j=0;j<MAXN;j++){
             if(!vis[j]){
                 sg[i]=j;
                 break;
             };
        }
    }
    int ret=0;
    for(int i=1;i<=N;i++){
        ret^=sg[A[i]];
    }
    if(ret){
        printf("Alice\n");
    }else{
         printf("Bob\n");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
