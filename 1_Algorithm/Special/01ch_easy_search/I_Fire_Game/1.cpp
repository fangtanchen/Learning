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
const int MAXN=14;
const int INF=0x1f1f1f1f;

int dist[110][110];
char map[14][14];
int T,N,M;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
         printf("Case %d: ",ti);
         scanf("%d%d",&N,&M);
         for(int ri=1;ri<=N;ri++){
             scanf("%s",map[ri]+1);
         }
         memset(dist,INF,sizeof(dist));
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
