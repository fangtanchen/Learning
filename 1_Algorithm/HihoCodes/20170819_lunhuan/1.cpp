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
const int MAXN=1005;

int A[MAXN],B[MAXN],id[MAXN],N;
bool vis[MAXN];

bool Cmp(int x,int y){
    return A[x]<A[y];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    while(cin>>N){
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=N;i++){
            cin>>A[i];
            B[i]=A[i];
            id[i]=i;
        }
        sort(B+1,B+N+1);
        sort(id+1,id+N+1,Cmp);
        for(int i=1;i<=N;i++){
            cout<<id[i]<<" ";
        }
        cout<<endl;
        int ans=0;
        for(int i=1;i<=N;i++){
            if(vis[i])continue;
            int cnt=0;
            int u=i;
            while(!vis[u]){
                vis[u]=true;
                u=id[u];
                cnt++;
            }
            cnt--;
            ans+=cnt;
        }
        cout<<ans<<endl<<endl<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
