#include<iostream>
#include<vector>

using namespace std;
const int MAXN=1e5+10;


int N;
int P[MAXN];
int K;
vector<int> G[MAXN];

int main(){
    scanf("%d",&N);
    P[0]=0;
    for(int i=1;i<=N;i++){
        scanf("%d",P+i);
        P[i]=P[i]+P[i-1];
    }
    scanf("%d",&K);
    int ans=0;
    for(int i=1;i<=N;i++){
        P[i]%=K;
        if(P[i]==0)ans=max(ans,i);
        G[P[i]].push_back(i);
    }
    for(int i=0;i<K;i++){
        if(G[i].size()<=0)continue;
        int r=G[i].size();
        ans=max(ans,G[i][r-1]-G[i][0]);
    }
    printf("%d\n",ans);

    return 0;
}
