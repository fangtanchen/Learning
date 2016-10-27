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
const int MAXN=210;
const int MAXM=110;


class Path{
    public:
        int len;
        int s[MAXM];

        Path(){
            len=0;
            memset(s,0,sizeof(s));
        }
        Path(const Path &x){
             len=x.len;
             memcpy(s,x.s,sizeof(s));
        }
        void Add(int i){
            s[i]=1;
            len=i+1;
        }
};


Path path[MAXN];
bool vis[MAXN];
bool tmpvis[MAXN];
int lef[MAXM];

int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

        while(scanf("%d",&N),N){
            int tmpN=N;
            lef[0]=1%tmpN;
            for(int i=1;i<MAXM;i++){
                lef[i]=(lef[i-1]*10)%tmpN;
            }
            memset(vis,false,sizeof(vis));
            memset(path,0,sizeof(path));
            for(int i=0;i<MAXM;i++){
                memcpy(tmpvis,vis,sizeof(vis));

                if(!tmpvis[lef[i]]){
                    tmpvis[lef[i]]=true;
                    path[lef[i]].Add(i);
                }
                for(int mi=0;mi<N;mi++){
                    if(!vis[mi])continue;
                    int tmpmi=(mi+lef[i])%N;
                    if((!tmpvis[tmpmi])){
                        tmpvis[tmpmi]=true;
                        path[tmpmi]=path[mi];
                        path[tmpmi].Add(i);
                    }
                }
                memcpy(vis,tmpvis,sizeof(vis));
                if(vis[0]){
                    break;
                }
            }
            for(int i=path[0].len-1;i>=0;i--){
                 printf("%d",path[0].s[i]);
            }
            printf("\n");
        }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
