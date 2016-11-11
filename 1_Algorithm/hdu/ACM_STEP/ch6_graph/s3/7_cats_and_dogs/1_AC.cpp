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
const int MAXN=40100;
const int MAXM=400000;
const int MODN=300;

int l[MAXN][2];
int c,d,v,T;
bool vis[MAXN];
int mp[MAXN];
int top,first[MAXN],to[MAXM],adj[MAXM];

void Init(){
     memset(vis,false,sizeof(vis));
     memset(mp,-1,sizeof(mp));
     memset(first,-1,sizeof(first));
     memset(to,-1,sizeof(to));
     memset(adj,-1,sizeof(adj));
     top=0;
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

int FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((-1==mp[v])||FindPath(mp[v])){
            mp[v]=u;
            return 1;
        }
    }
    return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>T;
    while(T--){
         Init();
         cin>>c>>d>>v;
         for(int vi=1;vi<=v;vi++){
             char ch;
             int id;
             for(int i=0;i<2;i++){
                 cin>>ch>>id;
                 if(ch=='D')id+=MODN;
                 l[vi][i]=id;
             }
             for(int ui=1;ui<vi;ui++){
                 if(l[ui][0]==l[vi][1]
                         ||l[ui][1]==l[vi][0]){
                     Add(ui,vi);
                     Add(vi,ui);
                 }
             }
         }
         int ans=0;
         for(int ui=1;ui<=v;ui++){
          //   if((mp[ui]==-1))
            {
                 memset(vis,false,sizeof(vis));
                 vis[ui]=true;
                 ans+=FindPath(ui);
             }
         }
         cout<<v-ans/2<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
