#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e6+5;
const int MAXS=26;

#define MEM(x,a) memset(x,a,sizeof(x))

int maxlen[MAXN*2],minlen[MAXN*2],trans[MAXN*2][MAXS],slink[MAXN*2];
int n;
char str[MAXN];

void Init(){
    MEM(maxlen,0) ;
    MEM(minlen,0);
    MEM(trans,-1);
    MEM(slink,-1);
    n=1;
}

int NewState(int _maxlen,int _minlen,int *_trans,int _slink){
    maxlen[n]=_maxlen;
    minlen[n]=_minlen;
    slink[n]=_slink;
    for(int i=0;i<MAXS;i++){
        if(_trans!=NULL){
            trans[n][i]=_trans[i];
        }else{
             trans[n][i]=-1;
        }
    }
    return n++;
}

int AddState(char ch,int u){
    int c=ch-'a';
    int z=NewState(maxlen[u]+1,-1,NULL,-1);
    int v=u;
    while((v!=-1)&&(trans[v][c]==-1)){
        trans[v][c]=z;
        v=slink[v];
    }
    if(v==-1){
        minlen[z]=1;
        slink[z]=0;
        return z;
    }
    int x=trans[v][c];
    if(maxlen[v]+1==maxlen[x]){
         minlen[z]=maxlen[x]+1;
         slink[z]=x;
         return z;
    }
    int y=NewState(maxlen[v]+1,-1,trans[x],slink[x]);
    slink[y]=slink[x];
    minlen[x]=maxlen[y]+1;
    slink[x]=y;
    slink[z]=y;
    minlen[z]=maxlen[y]+1;
    int w=v;
    while((w!=-1)&&(trans[w][c]==x)){
        trans[w][c]=y;
        w=slink[w];
    }
    minlen[y]=maxlen[slink[y]]+1;
    return z;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%s",str);
    int len=strlen(str);
    int u=0;
    for(int i=0;i<len;i++){
         u=AddState(str[i],u);
    }
    long long int ans=0;
    for(int i=1;i<n;i++){
        ans+=maxlen[i]-minlen[i]+1;
    }
    printf("%lld\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
