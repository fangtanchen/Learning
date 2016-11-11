#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MODN=100;
const int MAXN=10000;
const int MAXM=2e5+10;
const int MAXS=12;
const int dir[12][2]={{-1,-2},{-2,-1},{-2,1},{-1,2},
    {1,2},{2,1},{2,-1},{1,-2},{-1,0},{0,1},{1,0},{0,-1}};

class Node{
    int ri,ci;
    int id;
    Node(int a,int b){
        ri=a;ci=b;
        id=ri*MODN+ci;
    }
    Node(const Node &p){
        ri=p.ri;
        ci=p.ci;
    }
};

bool vis[MAXN];
int mp[MAXN];
int R,C;
int G[55][55];



void Init(){
    memset(vis,false,sizeof(vis));
    memset(mp,-1,sizeof(mp));
}


void convert(int val,int ans[13]){
    memset(ans,0,sizeof(ans));
    for(int i=0;i<12;i++){
        if(val&(1<<i))ans[i]=1;
    }
}

bool InMap(int ri,int ci){
    return (ri>=1)&&(ri<=R)&&(ci>=1)&&(ci<=C)&&(G[ri][ci]>=0);
}

int FindPath(int uri,int uci,int uid){
    for(int si=0;si<MAXS;si++){
        if((G[uri][uci]&(1<<si))==0)continue;
        int vri=uri+dir[si][0];
        int vci=uci+dir[si][1];
        int vid=vri*MODN+vci;
        if((!InMap(vri,vci))||vis[vid])continue;
        vis[vid]=true;
        int tmpri=mp[vid]/MODN;
        int tmpci=mp[vid]%MODN;
        if(mp[vid]==-1||FindPath(tmpri,tmpci,mp[vid])){
            mp[uid]=vid;
            mp[vid]=uid;
            return 1;
        }

    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int casei=1;
    while(scanf("%d%d",&R,&C),R||C){
        Init();
        for(int ri=1;ri<=R;ri++){
            for(int ci=1;ci<=C;ci++){
                scanf("%d",&G[ri][ci]);
            }
        }
        /*
        for(int ri=1;ri<=R;ri++){
            for(int ci=1;ci<=C;ci++){
                if(G[ri][ci]>0){
                    int id=MODN*ri+ci;
                    int nb[13];
                    convert(G[ri][ci],nb);
                    for(int si=0;si<MAXS;si++){
                        if(ans[si]>0){
                            int tmpri=ri+dir[si][0];
                            int tmpci=ci+dir[si][1];
                            if(InMap(tmpri,tmpci)){
                                int tmpid=tmpri*MODN+tmpci;
                                Add(id,tmpid);
                                Add(tmpid,id);
                            }
                        }
                    }
                }
            }
        }
        */
        int ans=0;
        for(int ri=1;ri<=R;ri++){
            for(int ci=1;ci<=C;ci++){
                int id=ri*MODN+ci;
                if(G[ri][ci]>=0&&mp[id]==-1){
                    memset(vis,false,sizeof(vis));
                    vis[id]=true;
                    ans+=FindPath(ri,ci,id);
                }
            }
        }
        printf("%d. %d\n",casei++,ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
