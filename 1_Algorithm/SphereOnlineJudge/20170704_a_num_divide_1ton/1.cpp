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
typedef long long int LL;
const int MAXN=6e6;
const int MODU=1e8+7;

bool isPrime[MODU];
int primeList[MAXN];
int pcnt;



LL Solve(int n){
    LL ans=1;
    memset(isPrime,true,sizeof(isPrime));
    pcnt=0;
    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            primeList[pcnt++]=i;
            LL tmp=i;
            while(tmp<=n)tmp*=i;
            tmp/=i;
            ans=ans*tmp%MODU;
        }
        for(int pi=0;pi<pcnt;pi++){
            LL tmp=primeList[pi]*i;
            if(tmp>n)break;
            isPrime[tmp]=false;
            if(i%primeList[pi]==0)break;
        }
    }
    return ans;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n;
    cin>>n;

    LL ans=Solve(n);
    cout<<ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
