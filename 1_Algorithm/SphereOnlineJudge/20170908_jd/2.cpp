#include<iostream>

using namespace std;
typedef long long LL;

const int MAXN=1e6+10;
const LL MODU=1e9+7;

LL num[MAXN];

int main(void){
    LL N;

    cin>>N;
    num[0]=0;
    for(int i=1;i<=N;i++){
        num[i]=N/i;
    }
    for(int i=3;i<=N;i++){
        num[i]+=num[i-1];
    }
    LL ans=0;
    for(int i=2;i<=N;i++){
        LL p=0;
        LL tmp=i;
        while(tmp<=N){
            p++;
            tmp*=i;
        }
        ans=(ans+num[1])%MODU;
        if(p<=1)continue;
        ans=(ans+num[p])%MODU;
        ans=(ans+num[p])%MODU;
    }
    LL a,b,flag;
    a=b=N;
    flag=1;
    while(b>=flag){
        if(b&flag){
            ans=(ans+a)%MODU;
        }
        flag<<=1;
        a=(a+a)%MODU;
    }
    cout<<ans<<endl;

    return 0;
}
