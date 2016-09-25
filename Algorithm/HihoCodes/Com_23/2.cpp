#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1<<14+10;

int f[MAXN];
int n;
int ans[MAXN];
bool vis[25];



void Init(){
    memset(ans,-1,sizeof(ans));
    memset(vis,false,sizeof(vis));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    scanf("%d",&n);
    Init();
    int imax=1<<n;
    for(int i=0;i<imax;i++){
        scanf("%1d",f+i);
         ans[i]=n;
    }

    for(int i=0;i<imax;i++){
        if(!vis[f[i]]){
            int res=i;
            for(int j=0;j<imax;j++) {
                if(f[i]==f[j]){
                    res=~(res^j);
                }
            }
            int pp=0;
            for(int j=1;j<imax;j*=2){
                if(j&res)pp++;
            }
            ans[i]=pp;
            vis[f[i]]=true;
            for(int j=i+1;j<imax;j++){
                 ans[j]=ans[i];
            }
        }
    }
    cout<<ans[0];
    for(int i=1;i<imax;i++){
        printf(" %d",ans[i]);
    }
    cout<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
