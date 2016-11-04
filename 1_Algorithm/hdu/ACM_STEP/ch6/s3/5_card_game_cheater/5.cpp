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
const int MAXN=200;
const int MAXM=2000;

int top,first[MAXN],to[MAXM],adj[MAXM];
char str[10];
int num[MAXN];
int mp[MAXN];
bool vis[MAXN];
int N,K;

void Init(){
    top=0;
    memset(first,-1,sizeof(first));
    memset(to,-1,sizeof(to));
    memset(adj,-1,sizeof(adj));
    memset(num,0,sizeof(num));
    memset(mp,-1,sizeof(mp));
    memset(vis,false,sizeof(vis));
}

void Add(int u,int v){
    adj[top]=first[u];
    to[top]=v;
    first[u]=top++;
}

int Analyze(char *str){
    int ret;
    switch(str[0]){
        case 'T':
            ret=10;
            break;
        case 'J':
            ret=11;
            break;
        case 'Q':
            ret=12;
            break;
        case 'K':
            ret=13;
            break;
        case 'A':
            ret=14;
            break;
        default:
            ret=str[0]-'0';
    }
    ret*=10;
    switch(str[1]){
        case 'C':
            ret+=1;
            break;
        case 'D':
            ret+=2;
            break;
        case 'S':
            ret+=3;
            break;
        case 'H':
            ret+=4;
            break;
    }
    return ret;
}

int FindPath(int u){
    for(int pos=first[u];pos!=-1;pos=adj[pos]){
        int v=to[pos];
        if(vis[v])continue;
        vis[v]=true;
        if((mp[v]==-1)||FindPath(mp[v])){
            mp[u]=v;
            mp[v]=u;
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
    scanf("%d",&N);
    while(N--){
        Init();
         cin>>K;
         for(int ki=1;ki<=K;ki++){
             cin>>str;
             num[ki]=Analyze(str);
         }
         for(int ki=1,pi=101;ki<=K;ki++,pi++){
              cin>>str;
              num[pi]=Analyze(str);
              for(int j=1;j<=K;j++){
                  if(num[pi]>num[j]){
                      Add(pi,j);
                      Add(j,pi);
                  }
              }
         }
         int ans=0;
         for(int ki=1;ki<=K;ki++){
             if(-1==mp[ki]){
                 memset(vis,false,sizeof(vis));
                 vis[ki]=true;
                 ans+=FindPath(ki);
             }
         }
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
