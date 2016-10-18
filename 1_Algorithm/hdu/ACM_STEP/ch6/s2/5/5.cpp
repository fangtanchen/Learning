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
const int MAXN=21;
const int MAXM=3000;
const int DIST=2520;
const int INF=0x3f3f3f3f;


int H,V;
int dist[11];
int first[MAXM],to[MAXM],val[MAXM],adj[MAXM];
int top;
int ans[MAXM];
bool vis[MAXM];

void Init(){
    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(val,-1,sizeof(val));
    memset(adj,-1,sizeof(adj));
    top=0;
}

void Add(int u,int v,int w){
    adj[top]=first[u];
    to[top]=v;
    val[top]=w;
    first[u]=top++;
}

void AddEdge(int speed,int op,int si,int di){
    if(speed==0)return;
    switch(op){
        case '*':
            Add(si,di,dist[speed]);
            Add(di,si,dist[speed]);
            break;
        case '<':
            Add(di,si,dist[speed]);
            break;
        case '>':
            Add(si,di,dist[speed]);
            break;
        case 'v':
            Add(si,di,dist[speed]);
            break;
        case '^':
            Add(di,si,dist[speed]);
            break;
        default:
            break;
    }
    return;
}


void Dijkstra(int st,int ed){
    memset(vis,false,sizeof(vis));
    memset(ans,0x3f,sizeof(ans));
    vis[st]=true;
    ans[st]=0;
    for(int pos=first[st];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        int w=val[pos];
        ans[v]=min(ans[v],w);
    }

    int maxnum=(H+1)*(V+1)+1;
    while(1){
         int minv=INF,mini=-1;
         for(int i=1;i<maxnum;i++){
             if(vis[i])continue;
             if(ans[i]<minv){
                 minv=ans[i];
                 mini=i;
             }
         }
         if(mini==ed ||mini==-1)break;
         vis[mini]=true;
         for(int pos=first[mini];pos!=-1;pos=adj[pos]){
              int v=to[pos];
              int w=val[pos];
              if(vis[v])continue;
              ans[v]=min(ans[v],w+ans[mini]);
         }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

    cin.sync_with_stdio(false);
    dist[0]=INF;
    for(int i=1;i<10;i++){
         dist[i]=DIST/i;
    }

    while(cin>>V>>H,V||H){
        Init();
        int speed;
        char op;
        for(int i=0;i<V;i++){
            int si=(H+1)*i+1;
            int di=si+1;
            for(int pi=0;pi<H;pi++,si++,di++){
                cin>>speed>>op;
                AddEdge(speed,op,si,di);
            }
            si=(H+1)*i+1;
            di=(H+1)*(i+1)+1;
            for(int i=0;i<=H;i++,si++,di++){
                 cin>>speed>>op;
                 AddEdge(speed,op,si,di);
            }
        }
        int si=(H+1)*V+1;
        int di=si+1;
        for(int pi=0;pi<H;pi++,si++,di++){
            cin>>speed>>op;
            AddEdge(speed,op,si,di);
        }
        Dijkstra(1,(H+1)*(V+1));
        if(ans[(H+1)*(V+1)]==INF){
             printf("Holiday\n");
        }else{
            printf("%d blips\n",ans[(H+1)*(V+1)]);
        }

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
