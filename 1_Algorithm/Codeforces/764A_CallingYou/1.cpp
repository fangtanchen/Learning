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
const int MAXN=10005;

int N,M,Z;
bool n[MAXN],m[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d",&N,&M,&Z);
    memset(n,false,sizeof(n));
    for(int i=N;i<=Z;i+=N){
         n[i]=true;
    }
    int ans=0;
    for(int i=M;i<=Z;i+=M){
        if(n[i]){
            ans++;
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
