#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef pair<int,char> pic;

struct Node{
    int s[9];
    int ri,ci;
    int status;
    int cnt;
    Node(){
        memset(s,0,sizeof(s));
        ri=ci=0;
        status=-1;
        cnt=0;
    }
};
const int dir[4][2]={-1,0,1,0,0,-1,0,1};

char in[20];
Node st,ed;
queue<Node> Q;
int fac[9];
bool vis[(int)4e5+10];
map<int,pair<int,int> >pre;

bool InMap(int ri,int ci){
    return ri>=0&&ri<3&&ci>=0&&ci<3;
}

int Cantor(int s[]){
     int ret=0;
     for(int i=0;i<9;i++){
         int cnt=0;
         for(int j=i+1;j<9;j++){
             if(s[j]<s[i])cnt++;
         }
         ret+=cnt*fac[8-i];
     }
     return ret;
}

int BFS(const Node& st,int edval){
    memset(vis,false,sizeof(vis));
    while(!Q.empty())Q.pop();
    pre.clear();
    Q.push(st);
    vis[st.status]=true;
    pre[st.status]=make_pair(-1,-1);
    while(!Q.empty()){
        Node u=Q.front();
        Q.pop();
        if(u.status==edval)return u.cnt;
        for(int di=0;di<4;di++){
             Node v=u;
             v.ri=u.ri+dir[di][0];
             v.ci=u.ci+dir[di][1];
             if(!InMap(v.ri,v.ci))continue;
             int upos=3*u.ri+u.ci;
             int vpos=3*v.ri+v.ci;
             swap(v.s[upos],v.s[vpos]);
             v.status=Cantor(v.s);
             if(vis[v.status])continue;
             vis[v.status]=true;
             v.cnt=u.cnt+1;
             Q.push(v);
             pre[v.status]=make_pair(u.status,di);
             if(v.status==edval)return v.cnt;
        }
    }
    return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    fac[0]=1;
    for(int i=1;i<9;i++)fac[i]=i*fac[i-1];
    ed.ri=ed.ci=2;
    for(int i=0;i<9;i++){
        ed.s[i]=i+1;
    }
    ed.status=Cantor(ed.s);
    while(cin>>in[0]){
        for(int i=1;i<9;i++)cin>>in[i];
        for(int ri=0;ri<9;ri++){
            if('x'==in[ri]){
                st.s[ri]=9;
                st.ri=ri/3;
                st.ci=ri%3;
            }
            else st.s[ri]=in[ri]-'0';
        }
        st.status=Cantor(st.s);
        st.cnt=0;
        int flag=BFS(st,ed.status);
        if(-1==flag)puts("unsolvable");
        else{
            char ans[1000];
            char ch[5]="udlr";
            int k=ed.status;
            ans[flag]=0;
            while(k!=st.status){
                flag--;
                ans[flag]=ch[pre[k].second];
                k=pre[k].first;
            }
            puts(ans);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
