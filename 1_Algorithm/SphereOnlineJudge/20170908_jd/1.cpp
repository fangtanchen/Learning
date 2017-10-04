#include<iostream>

using namespace std;

typedef long long LL;

int main(){

    LL n,l,r;
    cin>>n;
    l=0,r=1.5e9;
    while(l<=r){
        LL mid=l+(r-l)/2;
        LL pr=(mid*(mid+1))/2;
        LL pl=(mid*(mid-1))/2+1;
        if(n>=pl&&n<=pr){
            cout<<mid<<endl;
            break;
        }else if(n<pl){
            r=mid-1;
        }else{
            l=mid+1;
        }
    }

    return 0;
}
