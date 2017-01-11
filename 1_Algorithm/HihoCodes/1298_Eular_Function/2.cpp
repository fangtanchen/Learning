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
const int MAXN=5e6+10;

int num[MAXN];
int primeList[MAXN];
int cnt_prime;
bool bPrime[MAXN];

int L,R;

void Init(){
     memset(num,0,sizeof(num));
     cnt_prime=0;
     memset(bPrime,true,sizeof(bPrime));
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&L,&R);
    Init();
    for(int i=2;i<=R;i++){
        if(bPrime[i]){
            primeList[cnt_prime++]=i;
            num[i]=i-1;
        }
        for(int pi=0;pi<cnt_prime;pi++){
            int tmp=i*primeList[pi];
            if(tmp>R)break;
            bPrime[tmp]=false;
            if(i%primeList[pi]==0){
                num[tmp]=num[i]*primeList[pi];
                break;
            }else{
                num[tmp]=num[i]*num[primeList[pi]];
            }
        }
    }
    int ans=L;
    for(int i=L+1;i<=R;i++){
        if(num[ans]>num[i]){
            ans=i;
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
