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
const int MAXN=15;

char map[MAXN][MAXN];
int N,K;
int ans;

bool cvis[MAXN];
bool rvis[MAXN];
class Point{
    public:
    int ri,ci;
    Point(int r=0,int c=0){
        ri=r;
        ci=c;
    }
};

Point pt[50000];
int ptnum;

void DFS(int n,int k){
    if(1==k){
        ans++;
        return;
    }
    rvis[pt[n].ri]=true;
    cvis[pt[n].ci]=true;
    for(int i=n+1;i<ptnum;i++){
        if((!rvis[pt[i].ri])&&(!cvis[pt[i].ci])){
            DFS(i,k-1);
        }
    }
    rvis[pt[n].ri]=false;
    cvis[pt[n].ci]=false;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d%d",&N,&K),(N!=-1)&&(K!=-1)){
            ptnum=0;
            for(int i=1;i<=N;i++){
                scanf("%s",map[i]+1);
                for(int j=1;j<=N;j++){
                    if(map[i][j]=='#'){
                        pt[ptnum].ri=i;
                        pt[ptnum].ci=j;
                        ptnum++;
                    }
                }
            }
            memset(cvis,false,sizeof(cvis));
            memset(rvis,false,sizeof(rvis));
            ans=0;
            for(int i=ptnum-K;i>=0;i--){
                //rvis[pt[i].ri]=true;
                //cvis[pt[i].ci]=true;
                DFS(i,K);
                //rvis[pt[i].ri]=false;
                //cvis[pt[i].ci]=false;
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
