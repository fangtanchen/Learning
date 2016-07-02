#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
#include<string>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=100010;
const int MAXP=200010;
const int MAXM=100010;

int N,M;
map<string,int> s2i;
map<int,string> i2s;
vector<int> G[MAXP];// collect child nodes
int in[MAXP];
int ques[MAXM][2];// collect question
vector<int> sta[MAXP];// collect related question nodesi
map<pair<int,int>,int> ans;
char vis[MAXP];
int fa[MAXP];

void Init(){
     memset(vis,0,sizeof(vis));
     memset(in,0,sizeof(in));
     s2i.clear();
     i2s.clear();
     for(int i=0;i<MAXP;i++){
         G[i].clear();
         sta[i].clear();
         fa[i]=i;
     }
     ans.clear();
}

int Find(int x){
    if(x==fa[x])return x;
    int fx=fa[x];
    int root=Find(fx);
    fa[x]=root;
    return root;
}

void DFS(int root){
   vis[root]=1;
   for(int i=sta[root].size()-1;i>=0;i--){
       int j=sta[root][i];
       if(vis[j]==0)continue;
       else if(vis[j]==1){
            ans[make_pair(root,j)]=j;
            ans[make_pair(j,root)]=j;
       }else{
           int fj=Find(j);
           ans[make_pair(root,j)]=fj;
           ans[make_pair(j,root)]=fj;
       }
   }
   for(int i=G[root].size()-1;i>=0;i--){
       DFS(G[root][i]);
       fa[G[root][i]]=root;
   }
   vis[root]=2;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d",&N);
    string name[2];
    int cnt=1;
    for(int i=0;i<N;i++){
        for(int j=0;j<2;j++){
            cin>>name[j];
            if(s2i[name[j]]==0){
                s2i[name[j]]=cnt;
                i2s[cnt]=name[j];
                cnt++;
            }
        }
        G[s2i[name[0]]].push_back(s2i[name[1]]);
        in[s2i[name[1]]]++;
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        cin>>name[0]>>name[1];
        int k0=s2i[name[0]];
        int k1=s2i[name[1]];
        if(k1<k0){
             int temp=k0;
             k0=k1;
             k1=temp;
        }
        ques[i][0]=k0;
        ques[i][1]=k1;
        if(k0==k1){
             ans[make_pair(k0,k1)]=k0;
             continue;
        }
        sta[k0].push_back(k1);
        sta[k1].push_back(k0);
    }
    for(int i=1;i<cnt;i++){
        if(in[i]==0){
            DFS(i);
        }
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
