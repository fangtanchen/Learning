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
vector<int> g[MAXN];
int fst[MAXN],snd[MAXN];
int in[MAXN];
int N;

void Init(){
    for(int i=1;i<=N;i++){
        g[i].clear();
    }
    memset(in,0,sizeof(in));
    memset(fst,0,sizeof(fst));
    memset(snd,0,sizeof(snd));
}
void post_traverse(int root){
    int len=g[root].size();
    if(len==0)return;
    int max1=0,max2=0;
    for(int i=0;i<len;i++){
        int k=g[root][i];
        post_traverse(k);
        if(fst[k]>max1){
            max2=max1;
            max1=fst[k];
        }
        else if(fst[k]>max2)max2=fst[k];
    }
    fst[root]=max1+1;
    if(1<len)snd[root]=max2+1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    Init();
    int a,b;
    for(int i=1;i<N;i++){
         scanf("%d%d",&a,&b);
         g[a].push_back(b);
         in[b]++;
    }
    for(int i=1;i<=N;i++){
        if(0==in[i]){
             post_traverse(i);
             break;
        }
    }
    int ans=0;
    for(int i=1;i<=N;i++){
        int temp=fst[i]+snd[i];
        if(ans<temp)ans=temp;
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
