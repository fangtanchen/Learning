#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=100010;
int N;
int fst[2*MAXN],snd[2*MAXN];
vector<int> G[2*MAXN];
int in[2*MAXN];

void Init(){
    memset(in,0,sizeof(in));
    memset(fst,0,sizeof(fst));
    memset(snd,0,sizeof(snd));
    for(int i=2*MAXN-1;i>=0;i--){
         G[i].clear();
    }
}

void PostOrder(int node){
    if(G[node].size()==0){
        return ;
    }
    for(int i=G[node].size()-1;i>=0;i--){
        int k=G[node][i];
        PostOrder(k);
        int f1=fst[k]+1;
        if(f1>fst[node]){
            snd[node]=fst[node];
            fst[node]=f1;
        }else if(f1>snd[node]){
             snd[node]=f1;
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<N;i++){
         int A,B;
         scanf("%d%d",&A,&B);
         if(A>B)swap(A,B);
         G[A].push_back(B);
         in[B]++;
    }
    PostOrder(1);
    int ans=0;
    for(int i=1;i<N;i++){
        int tmp=fst[i]+snd[i];
        if(ans<tmp)ans=tmp;
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
