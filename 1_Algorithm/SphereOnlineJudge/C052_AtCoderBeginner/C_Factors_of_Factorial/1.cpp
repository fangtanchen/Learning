#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
const int MODU=1e9+7;

bool isPrime[MAXN];
int primelist[MAXN];
int cntprime;
int num[MAXN];

void Init(){
    memset(isPrime,true,sizeof(isPrime));
    cntprime=0;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i<MAXN;i++){
        if(isPrime[i]){
             primelist[cntprime++]=i;
        }
        for(int pi=0;pi<cntprime;pi++){
            int tmp=primelist[pi]*i;
            if(tmp>=MAXN)continue;
            isPrime[tmp]=false;
            if(i%primelist[pi]==0)break;
        }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    int N;
    cin>>N;
    memset(num,0,sizeof(num));
    for(int ni=2;ni<=N;ni++){
        int tmpni=ni;
        for(int pi=0;pi<cntprime;pi++) {
             if(primelist[pi]>tmpni)break;
             if(0==tmpni%primelist[pi]){
                 while(0==tmpni%primelist[pi]){
                     num[pi]++;
                     tmpni/=primelist[pi];
                 }
             }
        }
    }
    long long int ans=1;
    for(int i=0;i<cntprime;i++){
        if(num[i]==0)continue;
        ans=ans*(num[i]+1)%MODU;
    }
    printf("%lld\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
