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
const int MAXN=40;
const int INF=0x7f7f7f7f;

struct Node{
    int i,j;
    int l;
    Node(){
        i=j=l=0;
    }
};

bool binset[MAXN];
int fa[MAXN];
Node cities[10000];
int num_cities;
int N;

void Init(){
    memset(binset,false,sizeof(binset));
    num_cities=0;
    memset(cities,0,sizeof(cities));
    for(int i=1;i<MAXN;i++){
        fa[i]=i;
    }
}

bool cmp(Node x, Node y){
    return x.l<y.l;
}

int Find(int x){
    if(x==fa[x])return x;
    fa[x]=Find(fa[x]);
    return fa[x];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N,N){
        Init();
        for(int ni=1;ni<N;ni++){
            char a,b;
            int num,l;
            cin>>a>>num;
            int tmpa=a-'A'+1;
            while(num--){
                cin>>b>>l;
                cities[num_cities].i=tmpa;
                cities[num_cities].j=b-'A'+1;
                cities[num_cities].l=l;
                num_cities++;
            }
        }
        sort(cities,cities+num_cities,cmp);
        int ans=0;
        for(int i=0;i<num_cities;i++){
            int a=cities[i].i,b=cities[i].j,l=cities[i].l;
            int pa=Find(a),pb=Find(b);
            if(pa==pb)continue;
            fa[pa]=pb;
            ans+=l;
        }
        cout<<ans<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
