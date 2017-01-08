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
const int MAXN=1e5+10;

int d[MAXN];
int num[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ni=0;ni<N;ni++){
         scanf("%d",num+ni);
    }
    if(N==1){
        printf("-1");
        return 0;
    }
    sort(num,num+N);
    if(N==2){
        int tmp=num[1]-num[0];
        if((tmp>1)&&(tmp&0x1==0))printf("3\n");
        else printf("2\n");
        printf("%d",2*num[0]-num[1]);
        if((tmp>1)&&(tmp&0x1==0))printf(" %d",);
        printf(" %d\n",2*num[1]-num[0]);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
