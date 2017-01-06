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
const int MAXN=10010;

int dir[4][11]={1,10,100,1000};
bool prime[MAXN];
bool vis[MAXN];

void Init(){
    memset(prime,true,sizeof(prime));
    prime[1]=false;
    int primeList[10000],pi=0;
    for(int i=2;i<MAXN;i++){
        if(prime[i]){

        }
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
