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
const int MAXN=1e5+10;

int G[MAXN];
int v[MAXN];
int u[MAXN];
int N,M,K;

set<int> s[MAXN];
set<int> s1[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    for(int i=1;i<=N;i++){
        for(int j=0;j<M;j++){
            int id=(i)*M+j;
            scanf("%d",G+id);
        }
    }
    for(int ci=0;ci<M;ci++){
        for(int ri=1;ri<=N;ri++){
            int t=ri-1;
            while((0!=t)&&(G[t*M+ci]<=G[ri*M+ci])){
                int tmp=v[t*M+ci];
                t=tmp/M;
            }
            v[ri*M+ci]=t*M+ci;
            s[ri].insert(t);
        }
    }
    for(int ci=0;ci<M;ci++){
        for(int ri=N;ri>0;ri--){
            int t=ri+1;
            while((N+1!=t)&&(G[t*M+ci]>=G[ri*M+ci])){
                int tmp=u[t*M+ci];
                t=tmp/M;
            }
            u[ri*M+ci]=t*M+ci;
            s1[ri].insert(t);
        }
    }
    scanf("%d",&K);
    while(K--){
         int l,r;
         scanf("%d%d",&l,&r);
         int k=(*s[r].begin());
         int k1=(*s1[l].end());
         if(k<=l&&(k1>=r))puts("Yes");
         else puts("No");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
