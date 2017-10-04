#include<iostream>
#include<algorithm>

using namespace std;

typedef long long ll;
const int MAXN=110;
const int MODU=1e9+7;

int n;
ll x[MAXN];

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }

    sort(x,x+n);
    ll ans=1;
    for(int i=0;i<n;i++){
        ans=(ans*(x[i]-i))%MODU;
    }
    cout<<ans<<endl;

    return 0;
}
