#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<string>
#include<map>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXN 220
#define MAXM 220

int N,M;
map<string,int> mp;
map<string,int>::iterator it;
map<int,string> mp2;
vector<int> G[MAXN];
bool vis[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    string name[2];
    mp.clear();
    mp2.clear();
    int cnt=1;
    for(int i=0;i<N;i++){
         cin>>name[0]>>name[1];
         for(int pi=0;pi<2;pi++){
             it=mp.find(name[pi]);
             if(it==mp.end()){
                  mp[name[pi]]=cnt;
                  mp2[cnt]=name[pi];
                  cnt++;
             }
         }
         G[mp[name[1]]].push_back(mp[name[0]]);
    }
    scanf("%d",&M);
    for(int i=1;i<=M;i++){
         cin>>name[0]>>name[1];
         if(name[0]==name[1]){
             cout<<name[0]<<'\n';
             continue;
         }
         if(mp.find(name[0])==mp.end()
                 ||mp.find(name[1])==mp.end() ){
             printf("-1\n");
             continue;
         }
         memset(vis,false,sizeof(vis));
         int k=mp[name[0]];
         vis[k]=true;
         while(!G[k].empty()){
              k=G[k][0];
              vis[k]=true;
         }

         k=mp[name[1]];
         while((!vis[k])&&(!G[k].empty())){
              k=G[k][0];
         }
         if(vis[k]){
             cout<<mp2[k]<<'\n';
         }else{
              cout<<-1<<"\n";
         }

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
