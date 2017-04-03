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
const int MAXN=4e5+10;

const int fac_n[10]={1,1,2,6,24,120,720,5040,40320,362880};
const int dir[4][2]={1,0,0,-1,0,1,-1,0};


int father[9][MAXN];
char move[9][MAXN];
bool vis[9][MAXN];


int Cantor(char s[]){
    int ret=0;
    for(int i=0;i<9;i++){
        int cnt=0;
        for(int j=i+1;j<9;j++){
            if(s[i]>s[j])cnt++;
        }
        ret+=cnt*fac_n[9-i-1];
    }
    return ret;
}

struct Status{
    char eight[9];
    int space;
    int status;
    Status(){
         memset(eight,0,sizeof(eight));
         space=0;
         status=0;
    }
    Status(char s[]){
        for(int i=0;i<9;i++){
             if(s[i]!='X'){
                 eight[i]=s[i]-'0';
             }
             else {
                 eight[i]=9;
                 space=i;
             }
        }
         status=Cantor(eight);
    }
}st,ed;

int T,N;


bool InMap(int ri,int ci){
    return ri>=0&&ri<3&&ci>=0&&ci<3;
}

queue<Status> Q;
void BFS(Status st,int pi){
    while(!Q.empty())Q.pop();
    memset(vis[pi],false,sizeof(vis[pi]));
    memset(move[pi],-1,sizeof(move[pi]));
    memset(father[pi],-1,sizeof(father[pi]));
    Q.push(st);
    vis[pi][st.status]=true;
    move[pi][st.status]=-1;
    father[pi][st.status]=-1;
    while(!Q.empty()){
        Status u=Q.front();
        Q.pop();
        int k=u.space;
        int x=k/3,y=k%3;
        for(int di=0;di<4;di++){
             int xx=x+dir[di][0];
             int yy=y+dir[di][1];
             if(!InMap(xx,yy))continue;
             Status v=u;
             v.space=3*xx+yy;
             swap(v.eight[v.space],v.eight[k]);
             v.status=Cantor(v.eight);
             if(vis[pi][v.status])continue;
             vis[pi][v.status]=true;
             move[pi][v.status]=di;
             father[pi][v.status]=u.status;
             Q.push(v);
        }
    }
}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    char str[20]="X12345678";
    for(int i=0;i<9;i++){
        st=Status(str);
        BFS(st,i);
        swap(str[i],str[i+1]);
    }
    scanf("%d",&T);
    for(int ti=1;ti<=T;ti++){
        scanf("%s",str);
        st=Status(str);
        int pi=0;
        int mp[10],mpi=1;
        for(int i=0;i<9;i++){
            if(str[i]=='X'){
                pi=i;
            }else{
                mp[str[i]-'0']=mpi++;
            }
        }
        scanf("%s",str);
        for(int i=0;i<9;i++){
            if(str[i]!='X'){
                str[i]=mp[str[i]-'0'];
            }
        }
        ed=Status(str);
        char ans[1010];
        int anslen=0;
        int k=ed.status;
        while(father[pi][k]!=-1){
            switch(move[pi][k]){
                case 0:
                    ans[anslen++]='d';
                    break;
                case 1:
                    ans[anslen++]='l';
                    break;
                case 2:
                    ans[anslen++]='r';
                    break;
                case 3:
                    ans[anslen++]='u';
                    break;
            }
             k=father[pi][k];
        }
        ans[anslen]=0;
        printf("Case %d: %d\n%s\n",ti,anslen,ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
