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
const int MAXN=1e6+5;
const int MAXM=2e6+5;
const int MAXS=26;

#define MEM(x,a) memset(x,a,sizeof(x))

char str[MAXN];
int maxlen[MAXM],minlen[MAXM],trans[MAXM][MAXS],slink[MAXM],endpos[MAXM],in[MAXM];
bool tag[MAXM];
int n;


void Init(){
    MEM(maxlen,0);
    MEM(minlen,0);
    MEM(trans,-1);
    MEM(slink,-1);
    MEM(endpos,0);
    MEM(in,0);
    MEM(tag,false);
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
    tag[z]=true;
    int v=u;
    while((-1!=v)&&(-1==trans[v][c])){
         trans[v][c]=z;
         v=slink[v];
    }
    if(-1==v){
        minlen[z]=1;
        slink[z]=0;
        in[0]++;
        return z;
    }
    int x=trans[v][c];
    while(maxlen[v]+1==maxlen[x]){
        slink[z]=x;
        minlen[z]=maxlen[x]+1;
        in[x]++;
        return z;
    }
    int y=NewState(maxlen[v]+1,minlen[x],trans[x],slink[x]);
//    slink[y]=slink[x];
    //minlen[y]=minlen[x];
    slink[x]=y;
    minlen[x]=maxlen[y]+1;
    in[y]++;
    slink[z]=y;
    minlen[z]=maxlen[y]+1;
    in[y]++;
    int w=v;
    while((-1!=w)&&(trans[w][c]==x)){
         trans[w][c]=y;
         w=slink[w];
    }
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
         u=AddState(u,str[i]);
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
