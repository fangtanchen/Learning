#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

typedef unsigned long long ll;
#define SIZE 14
ll n;
ll maxDivisors, result;
const ll primes[] ={2,  3,  5,  7,  11,  13,  17,  19,  23,  29,  31,  37,  41,  43};

void DFS(ll primei,ll now,ll divisors,ll lastNi){
	if(divisors>maxDivisors
		||(divisors==maxDivisors && now<result)){
		maxDivisors=divisors;
		result=now;
	}
	now=primes[primei]*now;
	for(int i=1;(now<=n)&&(i<=lastNi);i++, now*=primes[primei]){
		DFS(primei+1, now, divisors*(i+1), i);
	}
	return ;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	scanf("%ld", &n);

	result=n;
	maxDivisors=0;
	for(ll i=1, now=primes[0];now<=n;i++, now*=primes[0]){
		DFS(1, now, i+1, i);
	}

	printf("%ld\n", result);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
