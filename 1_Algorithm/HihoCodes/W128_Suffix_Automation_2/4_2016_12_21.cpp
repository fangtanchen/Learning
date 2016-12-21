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


char str[MAXN];
int maxlen[2*MAXN],minlen[2*MAXN],trans[2*MAXN][26],slink[2*MAXN];
int n;

int NewState(int _maxlen,int _minlen,int *_trans,int _slink){
     maxlen[n]=_maxlen;
     minlen[n]=_minlen;
     slink[n]=_slink;
     if(_trans!=NULL){
         for(int i=0;i<26;i++){
             trans[n][i]=_trans[i];
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
         slink[z]=x;
         minlen[z]=maxlen[x]+1;
         return z;
    }
    int y=NewState(maxlen[v]+1,-1,trans[x],slink[x]);
    slink[y]=slink[x];
    slink[x]=y;
    minlen[x]=maxlen[y]+1;
    slink[z]=y;
    minlen[z]=maxlen[y]+1;

    int w=v;
    while((w!=-1)&&(trans[w][c]==x)){
         trans[w][c]=y;//fff
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
    maxlen[0]=minlen[0]=0;
    scanf("%s",str);
    int u=0;
    int len=strlen(str);
    memset(trans,-1,sizeof(trans));
    memset(slink,-1,sizeof(slink));
    n=1;
    for(int i=0;i<len;i++){
         u=AddState(str[i],u);
    }
    long long int ans=0;
    for(int ni=1;ni<n;ni++){
        ans+=maxlen[ni]-minlen[ni]+1;
    }
    printf("%lld\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
