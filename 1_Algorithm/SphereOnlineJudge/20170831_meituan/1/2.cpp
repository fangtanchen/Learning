#include<iostream>

const int MAX=100010;
using namespace std;


int N,K;
int arr[MAX],sum[MAX],cnt[MAX],l[MAX],r[MAX];

int main(){
    cin>>N;
    arr[0]=0;
    memset(sum,0,sizeof(sum));
    for(int i=1;i<=N;i++){
        cin>>arr[i];
        sum[i]=sum[i-1]+arr[i];
    }
    cin>>K;
    int res=0;
    for(int i=1;i<=N;i++){
        sum[i]=sum[i]%K;
        if(0==sum[i])res=max(res,i);
    }
    memset(cnt,0,sizeof(cnt));
    for(int i=1;i<=N;i++){
        if(0==cnt[sum[i]]){
            l[sum[i]]=i;
        }
        cnt[sum[i]]++;
        r[sum[i]]=i;
    }
    for(int i=0;i<K;i++){
        if(cnt[i]>0){
            res=max(res,r[i]-l[i]);
        }
    }
    cout<<res<<endl;

    return 0;
}
