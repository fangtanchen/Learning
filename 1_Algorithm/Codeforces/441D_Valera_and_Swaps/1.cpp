#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=3010;

int a[MAXN];
bool vis[MAXN];
int n,m;
vector<int> G[MAXN];

int call(){
    memset(vis,false,sizeof(vis));
    int ret=0;
    for(int i=1;i<=n;i++){
        G[i].clear();
        if(vis[a[i]])continue;
        int t=i;
        while(!vis[t]){
            vis[t]=true;
            G[i].push_back(t);
            t=a[t];
        }
        ret++;
        sort(G[i].begin(),G[i].end());
    }
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++){
         cin>>a[i];
    }
    cin>>m;
    m=n-m;
    int op=call();
    if(op>m){
        vector<int> tmp;
        for(int i=1;i<=n;i++){
            if(G[i].size()>0){
                tmp.push_back(G[i][0]);
            }
        }
        sort(tmp.begin(),tmp.end());
        printf("%d\n",op-m);
        for(int i=1;i<=op-m;i++){
            printf("%d %d ",tmp[0],tmp[i]);
        }
    }else if(op<m){
        printf("%d\n",m-op);
        while(op<m){
            pair<int,int> pi(n+1,n+1);
            for(int i=1;i<=n;i++){
                if(G[i].size()>=2){
                    pi=min(pi,pair<int,int>(G[i][0],G[i][1]));
                }
            }
            printf("%d %d ",pi.first,pi.second);
            swap(a[pi.first],a[pi.second]);
             op=call();
        }
    }else printf("0\n");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
