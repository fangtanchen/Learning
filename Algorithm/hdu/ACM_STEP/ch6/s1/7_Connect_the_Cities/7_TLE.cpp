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
const int MAXN=510;
const int MAXM=25010;
const int MAXK=110;
const int MAXF=0x3f3f3f3f;

struct Node{
    int i,j,l;
    Node(){
         i=j=l=0;
    }
};

Node edges[MAXM];
int le;//len_edges
int fa[MAXN];
int N,M,K;

void Init(){
    for(int i=1;i<=N;i++) {
        fa[i]=i;
    }
    le=0;
    memset(edges,0,sizeof(edges));
}

int Find(int x){
    int root=x;
    while(root!=fa[root]){
         root=fa[root];
    }
    int tmp;
    while(root!=x){
        tmp=fa[x];
        fa[x]=root;
        x=tmp;
    }
    return root;
}

bool Cmp(Node x,Node y){
    return x.l<y.l;
}

int scan(){
    char ch;
    while((ch=getchar()),ch<'0'||ch>'9')
        ;
    int ret=ch-'0';
    while((ch=getchar()),(ch>='0')&&(ch<='9')){
        ret=ret*10+ch-'0' ;
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    //cin.sync_with_stdio(false);
    int cases;
    cin>>cases;
    while(cases--){
        N=scan();
        M=scan();
        K=scan();
        Init();
        for(int i=0;i<M;i++){
             edges[i].i=scan();
             edges[i].j=scan();
             edges[i].l=scan();
        }
        int num_cities=N-1;
        for(int i=0;i<K;i++){
             int t,a,b,pa,pb;
             t=scan();
             a=scan();
             pa=Find(a);
             for(int j=1;j<t;j++){
                 b=scan();
                 pb=Find(b);
                 if(pb==pa)continue;
                 // merge smaller tree to bigger tree
                 // important,can reduce the cost on changing representative
                 if(pa<pb){
                     fa[pb]=pa;
                 }else{
                     fa[pa]=pb;
                 }
                 num_cities--;
             }
        }
        sort(edges,edges+M,Cmp);
        int ans=0;
        if(num_cities>0){
            for(int i=0;i<M;i++){
                int a=edges[i].i,b=edges[i].j,l=edges[i].l;
                int pa=Find(a),pb=Find(b);
                if(pa==pb)continue;
                 if(pa<pb){
                     fa[pb]=pa;
                 }else{
                     fa[pa]=pb;
                 }
                ans+=l;
                num_cities--;
                if(num_cities==0)break;
            }
        }
        if(num_cities>0)printf("-1\n");
        else printf("%d\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
