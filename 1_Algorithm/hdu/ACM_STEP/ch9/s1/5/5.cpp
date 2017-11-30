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
const int MAXN=300010;
const int MAXP=1e6+10;

int fa[MAXN],cnt[MAXN],len[MAXN];
int N,P;

void Init(){
    memset(len,0,sizeof(len));
    for(int i=0;i<MAXN;i++){
        fa[i]=i;
        cnt[i]=1;
    }
}

int Find(int u){
    if(u==fa[u])return u;
    int rt=Find(fa[u]);
    len[u]=len[u]+len[fa[u]];
    fa[u]=rt;
    return rt;
}

int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
#endif
    cin.sync_with_stdio(false);
    while(cin>>P){
        Init();
        while(P--){
            char op;
            int x,y;
            cin>>op;
            if(op=='M'){
                cin>>x>>y;
                int fx=Find(x),fy=Find(y);
                if(fx!=fy){
                     fa[fx]=fy;
                     len[fx]+=cnt[fy];
                     cnt[fy]+=cnt[fx];
                }
            }else{
                cin>>x;
                int fx=Find(x);
                cout<<len[x]<<endl;
            }
        }
    }


#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    system("out.txt");
#endif

    return 0;
}
