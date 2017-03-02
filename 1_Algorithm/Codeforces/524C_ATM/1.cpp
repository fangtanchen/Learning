#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=2e5+10;

vector<int> G[21];
int N,K,Q;
int a[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>K;
    for(int i=1;i<=N;i++)
        cin>>a[i];
    for(int ki=1;ki<=K;ki++){
        for(int i=1;i<=N;i++){
            G[ki].push_back(ki*a[i]);
        }
    }
    for(int ki=1;ki<=K;ki++){
        sort(G[ki].begin(),G[ki].end());
    }
    cin>>Q;
    while(Q--){
         int x;
         cin>>x;
         bool flag=false;
         int ans=55;
         for(int ki=1;ki<=K;ki++){
             for(int pi=0;pi<G[ki].size();pi++){
                 int y=G[ki][pi];
                 int d=x-y;
                 if(d<0)break;
                 if(d==0){
                     flag=true;
                     ans=min(ans,ki);
                     break;
                 }
                 int imax=K-ki;
                 for(int i=1;i<=imax;i++){
                     int l=0,r=G[i].size()-1;
                     while(l<=r){
                         int mid=(l+r)/2;
                         if(G[i][mid]==d){
                             ans=min(ans,ki+i);
                             flag=true;
                             break;
                         }else if(G[i][mid]>d){
                              r=mid-1;
                         }else{
                             l=mid+1;
                         }
                     }
                 }
             }
         }
         if(!flag)ans=-1;
         printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
