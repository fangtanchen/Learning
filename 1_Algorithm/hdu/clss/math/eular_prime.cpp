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

#define MAXN 100000
bool isprime[MAXN];
int primeList[MAXN];
int cntprime;

void init(){
    memset(isprime,true,sizeof(isprime));
    cntprime=0;
    isprime[0]=isprime[1]=false;
    for(int i=2;i<MAXN;i++){
        if(isprime[i]){
            primeList[cntprime++]=i;
        }
        for(int pi=0;pi<cntprime;pi++){
             int temp=i*primeList[pi];
             if(temp>=MAXN)break;
             isprime[temp]=false;
             if(i%primeList[pi]==0)break;
        }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
