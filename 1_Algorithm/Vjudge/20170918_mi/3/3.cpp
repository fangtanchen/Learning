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
const int MAXN=1e6+10;

int f[MAXN];


int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    f[0]=f[1]=1;
    for(int i=2;i<MAXN;i++){
        f[i]=f[i-1]+f[i-2];

    }
    int N;
    while(EOF!=scanf("%d",&N)){
        printf("%d\n",f[N]);

    }

#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
