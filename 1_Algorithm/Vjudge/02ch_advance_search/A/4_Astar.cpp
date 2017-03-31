#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cstdlib>
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

struct Node{
    public:
    int s[9];
    int ri,ci;
    int status;
    int f,g,h;
    Node(){
        ri=0;ci=0;
        memset(s,0,sizeof(s));
        status=0;
    }
    bool operator<(const Node& p) const{
        if(f<p.f)return false;
        else if((f==p.f)&&(h<p.h))return false;
        return true;
    }
};

const int dir[4][2]={-1,0,1,0,0,-1,0,1};
const char d[10]="udlr";

char input[50];
int fac_n[10];
Node st,ed;
bool vis[MAXN];


void Init(){
    fac_n[0]=fac_n[1]=1;
    for(int i=2;i<9;i++){
        fac_n[i]=i*fac_n[i-1];
    }
}

int Cantor(int a[]){
    int ret=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++){
            if(a[i]>a[j])cnt++;
        }
        ret+=cnt*fac_n[9-i-1];
    }
    return ret;
}

bool bSolve(const Node &p){
    int cnt=0;
    for(int i=0;i<9;i++){
        for(int j=i+1;j<9;j++){
            if(p.s[i]>p.s[j]&&p.s[i]&&p.s[j])cnt++;
        }
    }
    if(cnt&1)return false;
    else return true;
}

int Get_H(const Node &p){
    int ret=0;
    for(int i=0;i<9;i++){
        int t=p.s[i]-1;
        int ri=t/3;
        int ci=t%3;
        ret+=abs(ri-i/3)+abs(ci-i%3);
    }
    return ret;
}


bool InMap(int ri,int ci){
    return ri>=0&&ri<3&&ci>=0&&ci<3;
}

priority_queue<Node> SQ;
pair<int,int> path[MAXN];

void BFS(const Node &st,const Node &ed){
    memset(vis,false,sizeof(vis));
    memset(path,-1,sizeof(path));
    while(!SQ.empty())SQ.pop();
    SQ.push(st);
    path[st.status]=make_pair(-1,-1);
    vis[st.status]=true;
    while(!SQ.empty()){
        Node u=SQ.top();
        SQ.pop();
        if(u.status==ed.status)return ;
        for(int di=0;di<4;di++){
            Node v=u;
            v.ri=u.ri+dir[di][0];
            v.ci=u.ci+dir[di][1];
            if(!InMap(v.ri,v.ci))continue;
            int ti=3*v.ri+v.ci;
            swap(v.s[ti],v.s[3*u.ri+u.ci]);
            v.status=Cantor(v.s);
            if(vis[v.status])continue;
            vis[v.status]=true;
            v.g=u.g+1;
            v.h=Get_H(v);
            v.f=v.g+v.h;
            SQ.push(v);
            path[v.status]=make_pair(u.status,di);
            if(v.status==ed.status)return;
        }
    }
}

void Print(int si,int ed){
    if(si==ed)return;
    Print(path[si].first,ed);
    putchar(d[path[si].second]);
}
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(cin.getline(input,50,'\n')){
        Init();
        ed.ri=ed.ci=2;
        for(int i=0;i<9;i++){
            ed.s[i]=(i+1)%9;
        }
        ed.status=Cantor(ed.s);
        int si=0;
        for(int i=0;input[i];i++){
            if(input[i]!=' '){
                if(input[i]=='x'){
                     st.s[si]=0;
                     st.ri=si/3;
                     st.ci=si%3;
                }else{
                    st.s[si]=input[i]-'0';
                }
                si++;
            }
        }
        st.status=Cantor(st.s);
        st.g=0;
        st.h=Get_H(st);
        st.f=st.h+st.g;
        if(!bSolve(st)){
            cout<<"unsolvable"<<endl;
        }else{
            BFS(st,ed);
            int k=ed.status;
            Print(ed.status,st.status);
            printf("\n");
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
