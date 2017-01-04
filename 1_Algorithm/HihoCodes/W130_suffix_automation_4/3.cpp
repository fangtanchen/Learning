#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<queue>


#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+200;
const int MAXM=2e6+200;
const int MAXS=11;
const int MODU=1e9+7;


typedef long long int ll;
#define MEM(x,a) memset(x,a,sizeof(x));

int maxlen[MAXM],minlen[MAXM],slink[MAXM],trans[MAXM][MAXS];
int n;
ll sum[MAXM];
int npos[MAXM],in[MAXM];
char str[MAXM];

void Init(){
     MEM(maxlen,0);
     MEM(minlen,0);
     MEM(slink,-1);
     MEM(trans,-1);
     MEM(sum,0);
     MEM(npos,0);
     MEM(in,0);
     MEM(str,0);
     n=1;
}



int NewState(int _maxlen,int _minlen,int *_trans,int _slink){
    maxlen[n]=_maxlen;
    minlen[n]=_minlen;
    slink[n]=_slink;
    if(NULL!=_trans){
        for(int si=0;si<MAXS;si++){
             trans[n][si]=_trans[si];
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
     for(int si=0;si<MAXS;si++){
         if(trans[y][si]!=-1){
             in[trans[y][si]]++;
         }
     }
     slink[x]=y;
     minlen[x]=maxlen[y]+1;
     slink[z]=y;
     minlen[z]=maxlen[y]+1;
     int w=v;
     while((-1!=w)&&(x==trans[w][c])){
          trans[w][c]=y;
          in[y]++;
          w=slink[w];
     }
     in[x]-=in[y];
     return z;
}

void Topological(){
    queue<int> Q;
    Q.push(0);
    npos[0]=1;
    while(!Q.empty()){
         int u=Q.front();
         Q.pop();
         int imax=MAXS-1;
         for(int si=0;si<imax;si++){
             int v=trans[u][si];
             if(-1==v)continue;
             in[v]--;
             if(0==in[v])Q.push(v);
             sum[v]=(sum[v]+sum[u]*10+npos[u]*si)%MODU;
             npos[v]=(npos[u]+npos[v])%MODU;
         }
         int v=trans[u][imax];
         if(-1==v)continue;
         in[v]--;
         if(0==in[v])Q.push(v);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N;
    Init();
    scanf("%d",&N);
    int len=0;
    while(N--){
         scanf("%s",str+len);
         len=strlen(str);
         str[len++]=':';
    }
    int u=0;
    for(int si=0;si<len;si++ ){
         u=AddState(u,str[si]);
    }
    Topological();
    ll ans=0;
    for(int ni=0;ni<n;ni++){
         ans=(ans+sum[ni])%MODU;
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
