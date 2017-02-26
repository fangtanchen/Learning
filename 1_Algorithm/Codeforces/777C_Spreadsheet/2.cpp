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
const int MAXN=2e5+10;

int G[MAXN];
int v[MAXN];
int u[MAXN];
int N,M,K;

int s[MAXN];
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
            int id=ri*M+ci;
            int id1=(ri-1)*M+ci;
            if(G[id1]<=G[id]){
                v[id]=v[id1]+1;
            }else{
                v[id]=1;
            }
            s[ri]=max(s[ri],v[id]);
        }
    }
    scanf("%d",&K);
    while(K--){
         int l,r;
         scanf("%d%d",&l,&r);
         if(r-l+1<=s[r])puts("Yes");
         else puts("No");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
