// using  eratosthenes
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

#define MAXN 100010

int prime[MAXN];
int isprime[MAXN];
int cnt_prime;
int tree[MAXN];

int lowbit(int k){
    return k&-k;
}

int add(int k,int a){
    while(k<MAXN){
        tree[k]++;
        k+=lowbit(k);
    }
    return 0;
}
int query(int k){
     int sum=0;
     while(k>0){
         sum+=tree[k];
         k-=lowbit(k);
     }
     return sum;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    memset(prime,0,sizeof(prime));
    memset(isprime,true,sizeof(isprime));
    cnt_prime=0;

    isprime[0]=isprime[1]=false;
    for(int i=2;i<MAXN;i++){
        if(isprime[i]){
            prime[cnt_prime++]=i;
            if(isprime[i-2]){
                 add(i,1);
            }
        }
        for(int pi=0;pi<cnt_prime;pi++){
            int temp=i*prime[pi];
            if(temp>=MAXN)break;
            isprime[temp]=false;
            if(i%prime[pi]==0)break;
        }
    }
    int N;
    while(scanf("%d",&N),N>=0){
         printf("%d\n",query(N));
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
