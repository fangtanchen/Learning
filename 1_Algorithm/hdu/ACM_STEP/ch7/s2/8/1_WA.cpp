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

int J(int n,int a){
    if(n%a==0)return 0;
    int p[20],pcnt=0;
    int tmpa=a;
    for(int pi=0;pi<cntprime;pi++){
         if(primelist[pi]*primelist[pi]>tmpa)break;
         if(tmpa%primelist[pi]==0){
             p[pcnt++]=primelist[pi];
             while(0==tmpa%primelist[pi]){
                 tmpa/=primelist[pi];
             }
         }
    }
    if(tmpa!=1)p[pcnt++]=tmpa;

    int ret=1;
    for(int pi=0;pi<pcnt;pi++){
        if(0==n%p[pi]){
             ret=0;
             break;
        }
        else if(n%p[pi]==1){
            continue;
        }
        else if(p[pi]-1==n%p[pi])ret=ret*((((p[pi]-1)/2)&0x1)?-1:1);
        else if(2==n%p[pi])ret=ret*((((p[pi]*p[pi]-1)/8)&0x1)?-1:1);
        else {
            int tmp=(((p[pi]-1)*(n%p[pi]-1)/4)&0x1)?-1:1;
            //divide n
            int tmpn=n%p[pi];
            int n[20],pn=0;
            for(int i=0;i<cntprime;i++){
                if(primelist[i]*primelist[i]>tmpn)break;
                if(0==tmpn%primelist[i]){
                    int mu=J(p[pi]%primelist[i],primelist[i]);
                    int zi=(((p[pi]-1)*(primelist[i]-1)/4)&0x1)?-1:1;
                    int tmp=zi/mu;
                    while(0==tmpn%primelist[i]){
                        tmpn/=primelist[i];
                        ret*=tmp;
                    }
                }
            }
            if(1!=tmpn){
                int mu=J(p[pi]%tmpn,tmpn);
                int zi=(((p[pi]-1)*(tmpn-1)/4)&0x1)?-1:1;
                int tmp=zi/mu;
                ret*=tmp;
            }
        }
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
    while(EOF!=scanf("%d %d",&N,&A)){
        int ans=J(N,A);
        printf("%d\n",ans);
    }
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
