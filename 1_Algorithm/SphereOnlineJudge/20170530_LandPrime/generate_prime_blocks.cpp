#include<iostream>
#include<cstdio>
#include<cstring>


using namespace std;

typedef long long LL;
const int MAXN=1e8;
bool isPrime[MAXN];
int primeList[MAXN];
int cnt_prime;

void Init(){
    memset(isPrime,true,sizeof(isPrime));
    isPrime[1]=false;
    cnt_prime=0;
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
            primeList[cnt_prime++]=i;
        }
        for(int j=0;j<cnt_prime;j++){
            LL tmp=(LL)primeList[j]*(LL)i;
            if(tmp>=MAXN)break;
            isPrime[tmp]=false;
            if(0==i%primeList[j])break;
        }
    }
}

int main(){
    Init();
    int pos[1110];
    memset(pos,0,sizeof(pos));
    for(int i=1;i<=1010;i++){
        int l=(i-1)*50000+1,r=i*50000;
        for(int j=l;j<=r;j++){
            if(isPrime[j]){
                 pos[i]++;
            }
        }
        pos[i]+=pos[i-1];
    }
    printf("int pos[1110]={0");
    for(int i=1;i<=1010;i++){
         printf(",%d",pos[i]);
    }
    printf("}\n");
    return 0;
}
