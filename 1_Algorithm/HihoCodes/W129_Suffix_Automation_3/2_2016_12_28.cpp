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
const int MAXN=1e6+10;
const int MAXM=2e6+10;
const int MAXS=26;

#define MEM(x,a) memset(x,a,sizeof(x))

int maxlen[MAXM],minlen[MAXM],trans[MAXM][MAXS],slink[MAXM];
int in[MAXM],npos[MAXM],tag[MAXM];
int ans[MAXN];
char str[MAXN];
bool vis[MAXM];
int n;

void Init(){
     MEM(maxlen,0);
     MEM(minlen,0);
     MEM(trans,-1);
     MEM(slink,-1);
     MEM(npos,0);
     MEM(tag,0);
     MEM(ans,0);
     MEM(in,0);
     MEM(vis,false);
     n=1;
}

int NewState(int _maxlen,int _minlen,int *_trans,int _slink){
    maxlen[n]=_maxlen;
    minlen[n]=_minlen;
    slink[n]=_slink;
    if(_trans!=NULL){
        for(int i=0;i<MAXS;i++){
            trans[n][i]=_trans[i];
        }
    }
    return n++;
}

int AddState(int u,char ch){
    int c=ch-'a';
    int z=NewState(maxlen[u]+1,-1,NULL,-1);
    tag[z]=1;
    int v=u;
    while((v!=-1)&&(trans[v][c]==-1)){
         trans[v][c]=z;
         v=slink[v];
    }
    if(-1==v){
        slink[z]=0;
        in[0]++;
        minlen[z]=1;
        return z;
    }
    int x=trans[v][c];
    if(maxlen[x]==maxlen[v]+1){
        slink[z]=x;
        in[x]++;
        minlen[z]=maxlen[x]+1;
        return z;
    }
    int y=NewState(maxlen[v]+1,minlen[x],trans[x],slink[x]);
    slink[x]=y;
    minlen[x]=maxlen[y]+1;
    slink[z]=y;
    minlen[z]=maxlen[y]+1;
    in[y]+=2;
    int w=v;
    while((-1!=w)&&(trans[w][c]==x)){
         trans[w][c]=y;
         w=slink[w];
    }
    return z;
}

void TopologicalSort(){
    MEM(vis,false);
    for(int i=0;i<n;i++){
        if(in[i]==0 && (!vis[i])){
            npos[i]=1;
            queue<int> Q;
            Q.push(i);
            while(!Q.empty()){
                int u=Q.front();
                Q.pop();
                vis[u]=true;
                int v=slink[u];
                if(v==-1)continue;
                in[v]--;
                npos[v]+=npos[u];
                if(0==in[v]){
                    npos[v]+=tag[v];
                    Q.push(v);
                }
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%s",str);
    int slen=strlen(str);
    int u=0;
    for(int si=0;si<slen;si++){
        u=AddState(u,str[si]);
    }
    /*
    int ans=0;
    for(int i=1;i<n;i++){
        ans+=maxlen[i]-minlen[i];
        ans++;
    }
    printf("%d\n",ans);
    */
    TopologicalSort();
    for(int ni=0;ni<n;ni++){
        ans[maxlen[ni]]=max(ans[maxlen[ni]],npos[ni]);
    }
    for(int i=slen-1;i>=1;i--){
        ans[i]=max(ans[i],ans[i+1]);
    }
    for(int i=1;i<=slen;i++){
        printf("%d\n",ans[i]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
