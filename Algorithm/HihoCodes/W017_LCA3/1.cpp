#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

const int MAXN=100010;
const int MAXM=100010;
const int MAXS=200010;

map<string,int> s2i;
map<int,string> i2s;
vector<int> G[MAXN];
int depth[MAXN];
int in[MAXN];
int arr[MAXS];
int ai;
int n,m;
int cnt;


void DFS(int root){
    arr[ai]=root;
    ai++;
    for(int i=G[root].size()-1;i>=0;i--){
        depth[i]=depth[root]+1;
        DFS(i);
    }
    arr[ai]=root;
    ai++;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&n);
    string name[2];
    cnt=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++){
            cin>>name[j];
            if(s2i[name[j]]==0){
                s2i[name[j]]=cnt;
                i2s[cnt]=name[j];
                cnt++;
            }
        }
        int i1=s2i[name[0]],j1=s2i[name[1]];
        G[i1].push_back(j1);
        in[j1]++;
    }
    ai=0;
    for(int i=1;i<cnt;i++){
        if(0==in[i]){
            depth[i]=0;
            DFS(i);
        }
    }
    scanf("%d",&M);
    for(int i=0;i<M;i++){
        cin>>name[0]>>name[1];
        int tt[2]={0,0};

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
