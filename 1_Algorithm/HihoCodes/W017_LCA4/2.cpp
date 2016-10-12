#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<map>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
const int MAXL=21;
map<string,int> s2i;
string i2s[MAXN];
vector<int> G[MAXN];
int ath[MAXN][MAXL];
int depth[MAXN];
int N,M,num;

int GetNum(string str){
    map<string,int>::iterator it=s2i.find(str);
    if(it==s2i.end()){
        num++;
        i2s[num]=str;
        s2i.insert(make_pair(str,num));
    }
    return s2i[str];
}

void Build(){
    int root=1;
    while(ath[root][0]){
         root=ath[root][0];
    }
    queue<int> qe;
    qe.push(root);
    depth[root]=1;
    while(!qe.empty()){
        int p=qe.front();
        qe.pop();
        for(int i=1;i<MAXL;i++){
            ath[p][i]=ath[ath[p][i-1]][i-1];
        }
        vector<int>::iterator it;
        for(it=G[p].begin();it!=G[p].end();it++){
           depth[*it] =depth[p]+1;
           qe.push(*it);
        }
    }
}

int LCA(int p,int q){
    if(depth[p]<depth[q]){
        swap(p,q);
    }
    for(int i=MAXL-1;i>=0;i--){
        if(depth[ath[p][i]]>=depth[q]){
            p=ath[p][i];
        }
    }
    if(p==q)return p;
    for(int i=MAXL-1;i>=0;i--){
        if(ath[p][i]^ath[q][i]){
            p=ath[p][i];
            q=ath[q][i];
        }
    }
    return ath[p][0];
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(0);
    cin>>N;
    num=0;
    for(int i=0;i<N;i++){
         string a,b;
         cin>>a>>b;
         int na=GetNum(a),nb=GetNum(b);
         ath[nb][0]=na;
         G[na].push_back(nb);
    }
    Build();
    cin>>M;
    for(int i=0;i<M;i++){
        string a,b;
        cin>>a>>b;
        cout<<i2s[LCA(s2i[a],s2i[b])]<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
