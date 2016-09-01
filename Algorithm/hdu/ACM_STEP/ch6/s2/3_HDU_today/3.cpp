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
const int MAXN=1e4+10;
const int MAXM=200;
const int INF=0x5f5f5f5f;

int N;
map<string,int> s2i;
int snum;
vector<pair<int,int> > G[MAXM];
int inq[MAXM];
int dist[MAXM];
pair<int,int> qe[MAXN];
int head,tail;
bool vis[MAXM];

void Init(){
     s2i.clear();
     for(int i=0;i<MAXM;i++){
         G[i].clear();
     }
     memset(inq,-1,sizeof(inq));
     memset(dist,0x5f,sizeof(dist));
     head=tail=0;
     memset(qe,0,sizeof(qe));
     snum=0;
}

void Dijkstra(int si,int di){
    if(si==di){
        cout<<0<<endl;
        return;
    }
    memset(vis,false,sizeof(vis));
    memset(dist,0x5f,sizeof(dist));
    vis[si]=true;
    dist[si]=0;
    for(int i=G[si].size()-1;i>=0;i--){
        int b=G[si][i].first;
        if(vis[b])continue;
        int c=G[si][i].second;
        if(c<dist[b])dist[b]=c;
    }
    int mini,minv;
    do{
        mini=-1,minv=INF;
        for(int i=0;i<snum;i++){
            if(vis[i])continue;
            if(dist[i]<minv){
                minv=dist[i];
                mini=i;
            }
        }
        if(mini==-1)break;
        if(mini==di)break;
        vis[mini]=true;
        for(int i=G[mini].size()-1;i>=0;i--){
            int b=G[mini][i].first,c=G[mini][i].second;
            if(vis[b])continue;
            int tmp=c+dist[mini];
            if(tmp<dist[b])dist[b]=tmp;
        }
    }while(1);
    if(mini==-1)cout<<-1<<endl;
    else cout<<dist[di]<<endl;

}



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>N,-1!=N){
        Init();
        string si,di;
        string a,b;
        int c;
        //map<string,ing>::iterator it;
        cin>>si>>di;
        a=si,b=di;
        if(s2i.find(a)==s2i.end()){
             s2i[a]=snum++;
        }
        if(s2i.find(b)==s2i.end()){
             s2i[b]=snum++;
        }

        for(int i=0;i<N;i++){
            cin>>a>>b>>c;
            if(s2i.find(a)==s2i.end()){
                s2i[a]=snum;
                snum++;
            }
            if(s2i.find(b)==s2i.end()){
                s2i[b]=snum;
                snum++;
            }
            G[s2i[a]].push_back(make_pair(s2i[b],c));
            G[s2i[b]].push_back(make_pair(s2i[a],c));
        }
        int k1=s2i[si],k2=s2i[di];
        Dijkstra(k1,k2);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
