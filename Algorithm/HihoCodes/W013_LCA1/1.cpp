#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<string>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAXN 205
#define MAXM 205

map<string,int> mp;
map<int, string> mp2;
map<string,int>::iterator it;
vector<int> G[MAXN];
int in[MAXN];
int N,M;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);

    mp.clear();
    mp2.clear();
    string name[2];
    int cnt=0;
    for(int i=1;i<=N;i++){
        cin>>name[0]>>name[1];
        for(int pi=0;pi<2;pi++){
             it=mp.find(name[pi]);
             if(it==mp.end()){
                 cnt++;
                 mp[name[pi]]=cnt;
                 mp2[cnt]=name[pi];
             }
        }
        G[mp[name[1]]].push_back(mp[name[0]]);
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        memset(in,0,sizeof(in));
        cin>>name[0]>>name[1];
        if(name[0]==name[1]){
            cout<<name[0]<<endl;
            continue;
        }
        if(mp.find(name[0])==mp.end()
                ||mp.find(name[1])==mp.end()){
            cout<<-1<<endl;
            continue;
        }
        int id[2];
        id[0]=mp[name[0]];id[1]=mp[name[1]];
        int k=id[0];
        in[k]=1;
        while(!G[k].empty()){
            k=G[k][0];
            in[k]=1;
        }

        k=id[1];
        while(0==in[k]){
            if(G[k].empty()){
                break;
            }
            k=G[k][0];
        }
        if(in[k])cout<<mp2[k]<<endl;
        else cout<<-1<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
