#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1010;
const int INF=0x5f5f5f5f;


pair<int,int> que[MAXN];
int head,tail;
vector<pair<int,int> > G[MAXN];
int pos[MAXN];
int dist[MAXN];
int T,S,D;
int from[MAXN],to[MAXN];

void Init(){
     memset(que,0,sizeof(que));
     head=tail=0;
     for(int i=0;i<MAXN;i++){
         G[i].clear();
     }
     memset(pos,-1,sizeof(pos));
     memset(dist,0x5f,sizeof(dist));
}

void queue_push(pair<int,int> x){
    int tmp=(tail+1)%MAXN;
    if(tmp==head){
        printf("queue full\n");
        return;
    }
    que[tail]=x;
    pos[x.first]=tail;
    tail=(tail+1)%MAXN;
}

pair<int,int> queue_pop(){
    if(head==tail)return make_pair(0,INF);
    pair<int,int> x=que[head] ;
    head=(head+1)%MAXN;
    return x;
}

bool queue_empty(){
    return head==tail;
}

int SPFA(int si,int to[],int tolen){
    memset(dist,0x5f,sizeof(dist));
    memset(pos,-1,sizeof(pos));
    dist[si]=0;
    queue_push(make_pair(si,0));
    while(!queue_empty()){
        pair<int,int> db=queue_pop();
        int db_b=db.first,db_c=db.second;
        pos[db_b]=-1;
        if(db_c<dist[db_b])
            dist[db_b]=db_c;

        for(int i=G[db_b].size()-1;i>=0;i--){
            int nb_b=G[db_b][i].first,nb_c=G[db_b][i].second;
            int tmpdist=nb_c+dist[db_b];
            if(tmpdist>dist[nb_b])continue;
            if(-1==pos[nb_b]){
                 queue_push(make_pair(nb_b,tmpdist));
            }else if(tmpdist<que[pos[nb_b]].second){
                que[pos[nb_b]].second=tmpdist;
            }
        }
    }
    int ret=INF;
    for(int i=0;i<tolen;i++) {
        if(dist[to[i]]<ret){
             ret=dist[to[i]];
        }
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>T>>S>>D){
        Init();
        for(int i=0;i<T;i++){
            int a,b,c;
            cin>>a>>b>>c;
            G[a].push_back(make_pair(b,c));
            G[b].push_back(make_pair(a,c));
        }
        for(int i=0;i<S;i++){
            cin>>from[i] ;
        }
        for(int i=0;i<D;i++){
            cin>>to[i];
        }
        int ans=INF;
        for(int i=0;i<S;i++){
            int tmp=SPFA(from[i],to,D);
            if(tmp<ans)ans=tmp;
        }
        cout<<ans<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
