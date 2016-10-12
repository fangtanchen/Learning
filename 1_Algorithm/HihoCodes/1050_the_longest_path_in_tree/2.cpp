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
#define MAXN 100010

int N;
vector<int> G[MAXN];
int in[MAXN];
int fst[MAXN],snd[MAXN];
int max1=0;

void Init(){
    for(int i=1;i<=N;i++){
        G[i].clear();
    }
    memset(in, 0, sizeof(in));
    memset(fst,0,sizeof(fst));
    memset(snd,0,sizeof(snd));
    max1=0;
}

void PostOrder(int root){
    int i=root;
    for(int j=G[root].size()-1;j>=0;j--){
        int k=G[root][j];
        PostOrder(k);
        if(fst[k]>=fst[i]){
             snd[i]=fst[i];
             fst[i]=fst[k]+1;
        }else if(fst[k]>=snd[i]){
            snd[i]=fst[k]+1;
        }
    }
    if(max1<fst[i]+snd[i])max1=fst[i]+snd[i];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    Init();
    int a,b;
    for(int i=1;i<=N;i++){
         scanf("%d%d",&a,&b);
         G[a].push_back(b);
         in[b]++;
    }
    for(int i=1;i<=N;i++){
        if(0==in[i]){
            PostOrder(i);
            break;
        }
    }
    printf("%d\n",max1);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
