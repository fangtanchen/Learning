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
const int MAXP=400010;

map<string,int> s2i;
map<int,string> i2s;
vector<int> G[MAXS];
int depth[MAXS];
int in[MAXS];
int arr[MAXP];
int pos[MAXS];
int ai;
int n,m;
int cnt;


void DFS(int root){
    //arr[ai]=root;
    //ai++;
    for(int i=G[root].size()-1;i>=0;i--){
        arr[ai++]=root;
        int kk=G[root][i];
        depth[kk]=depth[root]+1;
        DFS(kk);
    }
    arr[ai]=root;
    pos[root]=ai;
    ai++;
}

void Init(){
    s2i.clear();
    i2s.clear();
    for(int i=1;i<=MAXS;i++)G[i].clear();
    memset(depth,0,sizeof(depth));
    memset(in,0,sizeof(in));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&n);
    Init();
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
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        cin>>name[0]>>name[1];
        int k0=s2i[name[0]],k1=s2i[name[1]];
        int pos0=pos[k0],pos1=pos[k1];
        if(pos1<pos0)swap(pos0,pos1);
        int res=depth[arr[pos0]];
        int kp=pos0;
        for(int i=pos0;i<=pos1;i++){
            if(res>depth[arr[i]]){
                res=depth[arr[i]];
                kp=i;
            }
        }
        cout<<i2s[arr[kp]]<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
