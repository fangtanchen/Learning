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

#define MAXN 5000010
bool isPrime[MAXN];
int primeList[MAXN];
int cnt[MAXN];
int primeCnt;
int L,R;

int init(){
    int imax=R+1;
     primeCnt=0;
     memset(isPrime,true,sizeof(isPrime));
     memset(primeList,0,sizeof(primeList));
     memset(cnt,0,sizeof(cnt));
     for(int i=2;i<imax;i++){
         if(isPrime[i]){
             primeList[primeCnt++]=i;
             cnt[i]=i-1;
         }
         for(int j=0;j<primeCnt;j++){
             int temp=primeList[j]*i;
             if(temp>imax)break;
             isPrime[temp]=false;
             if(i%primeList[j]){
                 cnt[temp]=cnt[i]*(primeList[j]-1);
             }else{
                 cnt[temp]=cnt[i]*primeList[j];
                 break;
             }
         }

     }
     return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&L,&R);
    init();
    int k=L;
    for(int i=L+1;i<=R;i++){
         if(cnt[i]<cnt[k])k=i;
    }
    printf("%d\n",k);



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
