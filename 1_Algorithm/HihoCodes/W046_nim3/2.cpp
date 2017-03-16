#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=2e4+10;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

int sg[MAXN];
int N,A[MAXN];
bool vis[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    sg[0]=0;
    for(int i=1;i<MAXN;i++){
        memset(vis,false,sizeof(vis));
        vis[sg[0]]=true;
        for(int j=1;j<i;j++){
            vis[sg[j]]=true;
            vis[(sg[j]^sg[i-j])]=true;;
        }
        int kk=0;
        while(vis[kk])kk++;
        sg[i]=kk;
    }
    cin>>N;
    int ans=0;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        ans^=sg[A[i]];
    }
    if(ans)puts("Alice");
    else puts("Bob");



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
