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
const int MAXS=11;
const int MODU=1e9+7;

#define MEM(x,a) memset(x,a,sizeof(x))


int maxlen[MAXM],minlen[MAXM],trans[MAXM][MAXS],slink[MAXM];
int npos[MAXM],sum[MAXM],in[MAXM];
bool vis[MAXM];
int N,n;
char str[MAXM];

void Init(){
    MEM(maxlen,0) ;
    MEM(minlen,0);
    MEM(trans,-1);
    MEM(slink,-1);
    MEM(npos,0);
    MEM(sum,0);
    MEM(str,0);
    MEM(in,0);
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
    int c=ch-'0';
    int z=NewState(maxlen[u]+1,-1,NULL,-1);
    int v=u;
    while((-1!=v)&&(-1==trans[v][c])){
        trans[v][c]=z;
        in[z]++;
        v=slink[v];
    }
    if(-1==v){
         slink[z]=0;
         minlen[z]=1;
         return z;
    }
    int x=trans[v][c];
    if(maxlen[v]+1==maxlen[x]){
         slink[z]=x;
         minlen[z]=maxlen[x]+1;
         return z;
    }
    int y=NewState(maxlen[v]+1,minlen[x],trans[x],slink[x]);
    slink[x]=y;
    minlen[x]=maxlen[y]+1;
    slink[z]=y;
    minlen[z]=maxlen[y]+1;
    int w=v;
    while((-1!=w)&&(trans[w][c]==x)){
         trans[w][c]=y;
         in[y]++;
         w=slink[w];
    }
    in[x]-=in[y];
    return z;
}

void Topological(){
    MEM(vis,false);
    for(int i=0;i<n;i++){
        if((0==in[i])&&(!vis[i]))
        {
            queue<int> Q;
            Q.push(i);
            npos[i]=1;
            sum[i]=0;
            while(!Q.empty()){
                int u=Q.front();
                Q.pop();
                vis[u]=true;
                int imax=MAXS-1;
                for(int i=0;i<imax;i++){
                     int v=trans[u][i];
                     if(-1==v)continue;
                     in[v]--;
                     npos[v]=(npos[u]+npos[v])%MODU;
                     sum[v]=(sum[u]*10+sum[v]+npos[u]*i)%MODU;
                     if(0==in[v]){
                          Q.push(v);
                     }
                }
                int v=trans[u][imax];
                if(v==-1)continue;
                in[v]--;
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
    scanf("%d",&N);
    scanf("%s",str);
    int len=strlen(str);
    for(int ni=1;ni<N;ni++){
         str[len++]=':';
         scanf("%s",str+len);
         len=strlen(str);
    }
    int u=0;
    for(int i=0;i<len;i++){
         u=AddState(u,str[i]);
    }
    /*
    int ans=0;
    for(int i=1;i<n;i++){
         ans+=maxlen[i]-minlen[i]+1;
    }
    printf("%d\n",ans);

     * */
    Topological();
    int ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+sum[i])%MODU;
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
