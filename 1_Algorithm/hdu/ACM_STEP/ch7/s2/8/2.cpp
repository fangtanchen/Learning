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
const int MAXN=1e6+5;

bool isPrime[MAXN];
int primelist[MAXN];
int cntprime;

void Init(){
     memset(isPrime,true,sizeof(isPrime));
     cntprime=0;
     isPrime[1]=false;
     for(int i=2;i<MAXN;i++){
         if(isPrime[i]){
             primelist[cntprime++]=i;
         }
         for(int pi=0;pi<cntprime;pi++){
             int tmp=i*primelist[pi];
             if(tmp>=MAXN)break;
             isPrime[tmp]=false;
             if(0==i%primelist[pi])break;
         }
     }
}

int L(int a,int n){
    if(1==a)return 1;
    if(n-1==a){
        return (((n-1)/2)&0x1)?-1:1;
    }
    if(2==a){
        return (((n*n-1)/8)&0x1)?-1:1;
    }
    int tmpa=a;
    int ret=1;
    for(int pi=0;pi<cntprime;pi++){
        if(primelist[pi]*primelist[pi]>tmpa)break;
        if(0==tmpa%primelist[pi]){
            int p=primelist[pi],q=n;
            int tmp=(((p-1)*(q-1)/4)&0x1)?-1:1;
            tmp=tmp/L(q%p,p);
            while(0==tmpa%primelist[pi]){
                ret*=tmp;
                tmpa/=primelist[pi];
            }
        }
    }
    if(1!=tmpa){
        int p=tmpa,q=n;
        int tmp=(((p-1)*(q-1)/4)&0x1)?-1:1;
        tmp=tmp/L(q%p,p);
        ret*=tmp;
    }
    return ret;
}

int J(int a,int n){
    if(0==a)return 0;
    int p[50],pcnt=0;
    int tmpn=n;
    for(int pi=0;pi<cntprime;pi++){
        if(primelist[pi]*primelist[pi]>tmpn)break;
        if(0==tmpn%primelist[pi]){
            while(0==tmpn%primelist[pi]){
                p[pcnt++]=primelist[pi];
                tmpn/=primelist[pi];
            }
        }
    }
    if(1!=tmpn){
        p[pcnt++]=tmpn;
    }
    int ret=1;
    if(p[0]==n){
        return L(a%n,n);
    }
    for(int pi=0;pi<pcnt;pi++){
        ret=ret*J(a%p[pi],p[pi]);
    }

    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Init();
    int N,A;
    while(EOF!=scanf("%d %d",&A,&N)){
        int ans=J(A,N);
        printf("%d\n",ans);
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
