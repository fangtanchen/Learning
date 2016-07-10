#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

const int maxn=200010;
const int maxl=21;

map<string,int> rn;
string name[maxn];
vector<int> e[maxn];
int ath[maxn][maxl],d[maxn],n,m,tn;

int GetNum(string str){
    map<string,int>::iterator it=rn.find(str);
    if(it==rn.end()){
        tn++;
        name[tn]=str;
        rn.insert(pair<string,int>(str,tn));
    }
    return rn[str];
}

int Build(){
    queue<int> qa;
    int root=1;
    while(ath[root][0]){
        root=ath[root][0];
    }
    qa.push(root);
    d[root]=1;
    while(!qa.empty()){
        int p=qa.front() ;
        qa.pop();
        for(int i=1;i<maxl;i++){
            ath[p][i]=ath[ath[p][i-1]][i-1];
        }

        for(vector<int>::iterator it=e[p].begin();
                it!=e[p].end();it++){
            d[*it]=d[p]+1;
            qa.push(*it);
        }
    }
    return 0;
}


int LCA(int x,int y){
    if(d[x]<d[y]){
        swap(x,y);
    }
    for(int i=maxl-1;i>=0;i--){
        if(d[ath[x][i]]>=d[y]){
            x=ath[x][i];
        }
    }
    if(x==y)return x;
    for(int i=maxl-1;i>=0;i--){
        if(ath[x][i]!=ath[y][i]){
             x=ath[x][i];
             y=ath[y][i];
        }
    }
    return ath[x][0];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(0);
    cin>>n;
    string a,b;
    tn=0;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        int na,nb;
        na=GetNum(a);
        nb=GetNum(b);
        ath[nb][0]=na;
        e[na].push_back(nb);
    }
    Build();
    cin>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        cout<<name[LCA(rn[a],rn[b])]<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
