#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+10;

vector<int> G[MAXN];
int N;
bool inq[MAXN];
int val[MAXN];
int pa[MAXN];

vector<int> BFS(vector<int> *G,int st){
    memset(inq,false,sizeof(inq));
    memset(val,0x7f,sizeof(val));
    memset(pa,-1,sizeof(pa));
    queue<int> Q;
    Q.push(st);
    val[st]=0;
    inq[st]=true;
    /*
    for(int i=0;i<G[st].size();i++){
        int v=G[st][i];
        Q.push(v);
        inq[v]=true;
        val[v]=0;
        pa[v]=0;
    }
    */
    while(!Q.empty()){
         int u=Q.front();
         Q.pop();
         inq[u]=false;
         for(int i=0;i<G[u].size();i++){
             int v=G[u][i];
             int tmpval=val[u]+(v-u)*(v-u);
             if(tmpval<val[v]){
                 if(inq[v]){
                     val[v]=tmpval;
                 }else{
                     Q.push(v);
                     inq[v]=true;
                     val[v]=tmpval;
                 }
                 pa[v]=u;
             }
         }
    }
    vector<int> ret;
    if(pa[9]==-1){
         ret.push_back(0);
         return ret;
    }else{
        int u=9;
        while(u!=-1){
            ret.push_back(u);
            u=pa[u];
        }
        reverse(ret.begin(),ret.end());
    }
    return ret;

}


vector<int> meet(vector<string> wizards){
    for(int i=0;i<wizards.size();i++){
        string str=wizards[i];
        int tmp=0;
        for(int j=0;j<=str.length();j++){
            if(j==str.length()||str[j]==' '){
                G[i].push_back(tmp);
                tmp=0;
            }
            else{
                 tmp=tmp*10+str[j]-'0';
            }
        }
    }
    vector<int> ret=BFS(G,0);
    return ret;
}


int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    scanf("%d",&N);
    vector<string> words;
    /*
    words.push_back("1 2 3");
    words.push_back("8 6 4");
    words.push_back("7 8 3");
    words.push_back("8 1");
    words.push_back("6");
    words.push_back("8 7");
    words.push_back("9 4");
    words.push_back("4 6");
    words.push_back("1");
    words.push_back("1 4");
    */
    words.push_back("1 2 3 4 5 6 7 8");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    words.push_back("9");
    vector<int> ans=meet(words);
    if(ans.size()==0)cout<<0<<endl;
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
