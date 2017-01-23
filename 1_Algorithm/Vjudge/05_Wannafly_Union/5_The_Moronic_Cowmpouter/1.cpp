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


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    long long int N;
    int digit[40],cntd;
    while(EOF!=scanf("%lld",&N)){
        if(N==0){
            printf("0\n");
            continue;
        }
        cntd=0;
        while(N){
            digit[cntd]=1&N;
            N=(N-digit[cntd])/-2;
            cntd++;
        }
        for(int di=cntd-1;di>=0;di--){
             printf("%d",digit[di]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
