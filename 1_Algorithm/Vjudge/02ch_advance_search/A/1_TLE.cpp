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
    int val;
    int ri,ci;
    int cnt;
    Node(){
        val=ri=ci=0;
        cnt=0;
    }
};
const int dir[4][2]={-1,0,1,0,0,-1,0,1};

char in[20];
Node st,ed;
map<int,pair<int,int> > pre;
queue<Node> Q;
int fac[20];

bool InMap(int ri,int ci){
    return ri>=0&&ri<3&&ci>=0&&ci<3;
}

int BFS(const Node& st,const Node &ed){
    pre.clear();
    while(!Q.empty())Q.pop();
    Q.push(st);
    pre[st.val]=make_pair(-1,-1);
    while(!Q.empty()){
         Node u=Q.front();
         Q.pop();
         if(u.val==ed.val)return u.cnt;
         int upos=3*u.ri+u.ci;
         for(int di=0;di<4;di++){
             Node v;
             v.ri=u.ri+dir[di][0];
             v.ci=u.ci+dir[di][1];
             if(!InMap(v.ri,v.ci))continue;
             int vpos=3*v.ri+v.ci;
             int k=u.val/fac[vpos]%10;
             v.val=u.val+k*fac[upos]-k*fac[vpos];
             if(pre.end()!=pre.find(v.val))continue;
             pre[v.val]=make_pair(u.val,di);
             v.cnt=u.cnt+1;
             Q.push(v);
             if(v.val==ed.val)return v.cnt;
         }
    }
    return -1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    char str[20]="123456780";
    ed.ri=ed.ci=2;
    ed.val=123456780;
    fac[8]=1;
    for(int i=7;i>=0;i--)fac[i]=fac[i+1]*10;
    while(cin>>in[0]){
        for(int i=1;i<9;i++)cin>>in[i];
        st.val=0;
        for(int ri=0;ri<3;ri++){
            for(int ci=0;ci<3;ci++){
                int i=3*ri+ci;
                if(in[i]=='x'){
                    in[i]='0';
                    st.ri=ri;
                    st.ci=ci;
                }
                st.val=st.val*10+in[i]-'0';
            }
        }
        int flag=BFS(st,ed);
        if(-1==flag)puts("unsolvable");
        else{
            char ans[1000];
            char ch[5]="udlr";
            int k=ed.val;
            ans[flag]=0;
            while(k!=st.val){
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
