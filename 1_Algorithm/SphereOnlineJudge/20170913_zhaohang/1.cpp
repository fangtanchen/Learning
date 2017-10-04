#include<iostream>
#include<vector>

using namespace std;

vector<int> G[300];
int M,N;
int in[300];
int pa[300];
int cnt[300];


int PostOrder(int rt,int n,int &ans){
    for(int i=0;i<G[rt].size();i++){
        int v=G[rt][i];
        cnt[rt]+=PostOrder(v,n,ans);
        cnt[rt]++;
    }
    if(cnt[rt]>=n)ans++;
    return cnt[rt];
}

int main(void){
    cin>>M>>N;
    memset(in,-1,sizeof(in));
    for(int i=0;i<300;i++)pa[i]=i;
    for(int i=0;i<M;i++){
        char a,b,c;
        cin>>a>>b>>c;
        if(b!='*'){
            G[a].push_back(b);
            in[b]++;
            pa[b]=a;
        }
        if(c!='*'){
            G[a].push_back(c);
            in[c]++;
            pa[c]=a;
        }
    }
    int ans=0;
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<300;i++){
        if(pa[i]==i)PostOrder(i,N,ans);
    }
    if(0==ans){
        cout<<"None"<<endl;
        return 0;
    }
    int tmp=ans;
    for(int i=0;i<300;i++){
        if(cnt[i]>=N){
            cout<<(char)i;
            ans--;
            if(ans)cout<<" ";
            else cout<<endl;
        }
    }

    return 0;
}
