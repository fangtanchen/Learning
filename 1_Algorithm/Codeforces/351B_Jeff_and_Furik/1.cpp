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
const int MAXN=3005;

int num[MAXN],sum[MAXN];
int N;

int LowBit(int x){
    return x&-x;
}

int Query(int x){
    int ret=0;
    while(x){
        ret+=sum[x];
        x-=LowBit(x);
    }
    return ret;
}
int Add(int x,int v){
    while(x<=N){
        sum[x]+=v;
        x+=LowBit(x);
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    memset(sum,0,sizeof(sum));
    int tmp=0;
    for(int ni=1;ni<=N;ni++){
         scanf("%d",num+ni);
         tmp=tmp+ni-1-Query(num[ni]);
         Add(num[ni],1);
    }

    double ans=tmp/2*4;
    if(tmp%2)ans++;
    printf("%.6lf\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
