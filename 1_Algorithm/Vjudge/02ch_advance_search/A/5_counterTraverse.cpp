#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=5e5+10;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;
const int dir[4][2]={-1,0,1,0,0,-1,0,1};

struct Node{
     public:
         int s[9];
         int status;
         int ri,ci;
         Node(){
              ri=ci=0;
              status=0;
              memset(s,0,sizeof(s));
         }
}st,ed;

int fac_n[10];
pair<int,int> path[MAXN];
bool vis[MAXN];


int Cantor(int s[]){
    int ret=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++){
            if(s[i]>s[j])cnt++;
        }
        ret+=fac_n[9-i-1]*cnt;
    }
    return ret;
}

bool InMap(int ri,int ci){
     return ri>=0&&ri<3&&ci>=0&&ci<3;
}

void BFS(){
    for(int i=0;i<9;i++){
        ed.s[i]=i+1;
    }
    ed.ri=ed.ci=2;
    ed.status=Cantor(ed.s);
    memset(vis,false,sizeof(vis));
    memset(path,-1,sizeof(path));
    queue<Node> Q;
    Q.push(ed);
    vis[ed.status]=true;
    path[ed.status]=make_pair(-1,-1);
    while(!Q.empty()){
         Node u=Q.front();
         Q.pop();
         for(int di=0;di<4;di++){
             Node v=u;
             v.ri=u.ri+dir[di][0];
             v.ci=u.ci+dir[di][1];
             if(!InMap(v.ri,v.ci))continue;
             swap(v.s[3*v.ri+v.ci],v.s[3*u.ri+u.ci]);
             v.status=Cantor(v.s);
             if(vis[v.status])continue;
             vis[v.status]=true;
             path[v.status]=make_pair(u.status,di);
             Q.push(v);
         }
    }
}

char chd[10]="durl";
char ans[MAXN],anslen;
bool Print(int s,int t){
    if(s==t)return true;
    if(s==-1)return false;
    ans[anslen++]=chd[path[s].second];
    bool flag=Print(path[s].first,t);
    return flag;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac_n[0]=fac_n[1]=1;
    for(int i=2;i<=9;i++)fac_n[i]=i*fac_n[i-1];
    BFS();
    char input[50];
    while(cin.getline(input,50,'\n')){
        int si=0;
        for(int i=0;input[i];i++){
            if(input[i]!=' '){
                if(input[i]=='x'){
                    st.ri=si/3;
                    st.ci=si%3;
                    st.s[si]=9;
                }else{
                    st.s[si]=input[i]-'0';
                }
                si++;
            }
        }
        st.status=Cantor(st.s);
        int k=st.status;
        anslen=0;
        memset(ans,0,sizeof(ans));
        bool flag=Print(st.status,ed.status);
        if(!flag)puts("unsolvable");
        else puts(ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
