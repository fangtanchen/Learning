#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=100010;
const int MAXM=100010;
const int MAXS=200010;

int N,M;
int num;
map<string,int> s2i;
map<int,string> i2s;
map<pair<int,int>,int> ans;
int fa[MAXS];
vector<int> G[MAXS];
vector<int> sta[MAXS];
int ques[MAXM][2];
int vis[MAXS];
int in[MAXS];

void Init(){
     num=1;
     s2i.clear();
     i2s.clear();
     ans.clear();
     for(int i=1;i<MAXS;i++){
          G[i].clear();
          fa[i]=i;
     }
     memset(vis,0,sizeof(vis));
     memset(in,0,sizeof(in));
}

int Find(int x){
    int fx=fa[x];
    if(fx==x)return x;
    fa[x]=Find(fx);
    return fa[x];
}

void DFS(int node){
    vis[node]=1;
    // collect answer
    for(int i=sta[node].size()-1;i>=0;i--){
        int child=sta[node][i];
        if(vis[child]==1){
            ans[make_pair(node,child)]=child;
            ans[make_pair(child,node)]=child;
        }else if(vis[child]==2){
            int fx=Find(child);
            ans[make_pair(child,node)] =fx;
            ans[make_pair(node,child)] =fx;
        }
    }

    for(int i=G[node].size()-1;i>=0;i--){
        int child=G[node][i];
        DFS(child);
        fa[child]=node;
    }

    vis[node]=2;

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    string name[2];
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            cin>>name[j];
            if(s2i[name[j]]==0){
                s2i[name[j]]=num;
                i2s[num]=name[j];
                num++;
            }
        }
        G[s2i[name[0]]].push_back(s2i[name[1]]);
        in[s2i[name[1]]]++;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        cin>>name[0]>>name[1];

        int k0=s2i[name[0]],k1=s2i[name[1]];
        ques[i][0]=k0,ques[i][1]=k1;
        if(k0==k1){
            ans[make_pair(k0,k1)]=k0;
            continue;
        }
        sta[k0].push_back(k1);
        sta[k1].push_back(k0);
    }
    for(int i=1;i<num;i++){
         if(in[i]==0)DFS(i);
    }
    for(int i=0;i<M;i++){
        cout<<i2s[ans[make_pair(ques[i][0],ques[i][1])]]<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
