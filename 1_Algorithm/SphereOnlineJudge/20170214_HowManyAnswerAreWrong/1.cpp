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
const int MAXN=2e5+10;

int pa[MAXN];
int w[MAXN];
int N,M;


int Find(int x){
    if(x==pa[x])return x;
    int p=pa[x];
    pa[x]=Find(p);
    w[x]+=w[p];
    return pa[x];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%d",&N,&M)){
            memset(w,0,sizeof(w));
            for(int i=0;i<MAXN;i++){
                pa[i]=i;
            }
            int ans=0;
            for(int i=1;i<=M;i++){
                int a,b,c;
                scanf("%d%d%d",&a,&b,&c);
                b++;
                int fa=Find(a);
                int fb=Find(b);
                if(fa==fb){
                     if(w[a]+c!=w[b])ans++;
                }else{
                    if(fa<fb){
                        pa[fb]=fa;
                        w[fb]=w[a]+c-w[b];
                    }else{
                        pa[fa]=fb;
                        w[fa]=w[b]-c-w[a];
                    }
                }
            }
            printf("%d\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
