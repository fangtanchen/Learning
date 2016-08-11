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
struct Node{
     int i,j;
     int len;
     Node(){
         i=j=len=0;
     }
};
const int MAXN=1e5+10;
const int MAXM=1e6+10;
Node edges[MAXM];
int fa[MAXN];
int N,M;
void Init(){
    for(int i=0;i<MAXN;i++){
        fa[i]=i;
    }
}

int Find(int x){
    if(x==fa[x])return x;
     int rt=Find(fa[x]);
     fa[x]=rt;
     return rt;
}
int Union(int x,int y){
     int fx=Find(x);
     int fy=Find(y);
     if(fx!=fy)fa[fx]=fy;
     return 0;
}

int cmp(Node x,Node y){
    return x.len<y.len;
}

int Kruscal(int nsize,int msize,int &ans){
    int num=nsize-1;
    int mi=0;
    ans=0;
    for(int mi=0;mi<msize;mi++){
        int fx=Find(edges[mi].i);
        int fy=Find(edges[mi].j);
        if(fx!=fy){
             num--;
             fa[fx]=fy;
             ans+=edges[mi].len;
        }
        if(!num)break;
    }
    return num;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    Init();
    cin>>N>>M;
    for(int i=0;i<M;i++){
         cin>>edges[i].i>>edges[i].j>>edges[i].len;
    }
    sort(edges,edges+M,cmp);
    int ans;
    Kruscal(N,M,ans);
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
