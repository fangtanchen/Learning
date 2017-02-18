#include<cstdio>

typedef long long int LL;
const LL MODU=1e9+7;

LL ModExp(LL a,LL b,LL p){
    LL ret=1;
    while(b){
        if(1&b)ret=(ret*a)%p;
        a=(a*a)%p;
        b>>=1;
    }
    return ret;
}

int main(){
    LL a=3,b=1000000000;
    LL t=ModExp(a,b-1,MODU);
    printf("%lld\n",t);

    return 0;
}
