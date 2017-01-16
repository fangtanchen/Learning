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
const int MAXN=100005;

char str[MAXN];
int pa[MAXN];
int v[MAXN];
int T,M;
vector<char> G[MAXN];

int Find(int x){
    if(x==pa[x])return x;
    pa[x]=Find(pa[x]);
    return pa[x];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    scanf("%d",&T);
    for(int i=0;i<T;i++){
         scanf("%s",str);
         int len=strlen(str);
         for(int i=0;str[i];i++){
             pa[i]=i;
         }
         scanf("%d",&M);
         for(int mi=0;mi<M;mi++){
             int u,v;
             scanf("%d%d",&u,&v);
             int pu=Find(u),pv=Find(v);
             if(pu!=pv)pa[pu]=pv;
         }
         for(int i=0;i<len;i++){
              G[i].clear();
              v[i]=0;
         }
         for(int i=0;i<len;i++){
             G[Find(i)].push_back(str[i]);
         }
         for(int i=0;i<len;i++){
              sort(G[i].begin(),G[i].end());
         }
         for(int i=0;i<len;i++){
             int tmp=Find(i);
             putchar(G[tmp][v[tmp]++]);
         }
         putchar('\n');
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
