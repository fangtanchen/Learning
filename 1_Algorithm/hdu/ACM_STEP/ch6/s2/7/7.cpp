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
const int MAXT=110;
const int MAXM=100010;
const int MAXN=10010;
const int INF=0x3f3f3f3f;

int T,nz,nr;
int first[MAXN],adj[MAXM],val[MAXM],to[MAXM];
int top;
int inq[MAXN];
int dist[MAXN];
int ans[MAXN];
int dui[MAXM];
int head,tail;
bool bus[MAXN];

void Init(){
    memset(first,-1,sizeof(first));
    memset(adj,-1,sizeof(adj));
    memset(val,-1,sizeof(val));
    memset(to,-1,sizeof(to));
    top=0;
    memset(inq,-1,sizeof(inq));
    memset(dist,0x3f,sizeof(dist));
    memset(ans,0,sizeof(ans));
    head=0;tail=0;
    memset(bus,false,sizeof(bus));
}

void Add(int u,int v,int w){
    adj[top]=first[u];
    to[top]=v;
    val[top]=w;
    first[u]=top++;
}
void Push(int x){
    if((tail+1)%MAXM==head){
        printf("the queue is full\n");
        return;
    }
    dui[tail]=x;
    tail=(tail+1)%MAXM;
}

int Top(){
    if(tail==head){
         printf("the queue is empty\n");
         return -1;
    }
     return dui[head];
}
void Pop(){
    if(tail==head){
         printf("the queue is empty\n");
         return -1;
    }
    head=(head+1)%MAXM;
}

void SPFA(int st){
    memset(inq,-1,sizeof(inq));
    memset(dist,0x3f,sizeof(dist));
    head=tail=0;
    dist[st]=0;
    inq[st]=tail;
    Push(st);
    while(tail!=head){
        int u=Top();
        Pop();
        inq[u]=-1;
        for(int pos=first[u];pos!=-1;pos=adj[pos]){
            int v=to[pos];
            int w=dist[u]+1;
            if(w<dist[v]){

            }

        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>T;
    while(T--){
         cin>>nz>>nr;
         for(int i=0;i<nz;i++){
             int id,mz;
             cin>>id>>mz;
             int v;
             for(int j=0;j<mz;j++){
                 cin>>v;
                 Add(id,v,1);
             }
         }
         for(int i=0;i<nr;i++){
             int mr,id;
             cin>>mr;
             while(mr--){
                  cin>>id;
                  bus[id]=true;
             }
         }
         for(int i=1;i<MAXN;i++){
             if(bus[i]){
                 SPFA(i);
                 for(int j=1;j<MAXM;j++){
                     ans[j]=max(ans[j],dist[j]);
                 }
             }
         }
         int res=INF;
         int resi=-1;
         for(int i=1;i<MAXN;i++){
             if(ans[i]<res){
                 res=ans[i];
                 resi=i;
             }
         }
         cout<<res+1<<" "<<resi<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
