#include<iostream>
#include<map>


using namespace std;
typedef long long LL;
typedef pair<int,LL> pii;


LL N;
LL sum[100];
LL fac[100];
map<pii, LL> mp;

void Init(){
    memset(sum,0,sizeof(sum));
    sum[0]=2;
    fac[0]=1;
    for(int i=1;i<=60;i++){
        sum[i]=(1LL)<<(i+1);
        sum[i]+=sum[i-1];
        fac[i]=(1LL)<<i;
    }
    mp.clear();
}


inline LL DFS(int k,LL n){
    if(n==0)return 1;
    if(n<0)return 0;
    map<pii,LL>::iterator it=mp.find(make_pair(k,n));    if(it!=mp.end()){
        return it->second;
    }
    if(k<0)return 0;
    if(sum[k]<n)return 0;
    LL ret=0;
    ret+=DFS(k-1,n);
    ret+=DFS(k-1,n-fac[k]);
    ret+=DFS(k-1,n-2*fac[k]);
    mp.insert(make_pair(make_pair(k,n),ret));
    return ret;
}

int main(){

    while(cin>>N){
        Init();
        int k=0;
        for(k=0;fac[k]<=N;k++)
            ;
        k--;
        LL ret=DFS(k,N);
        cout<<ret<<endl;

    }
    return 0;
}
