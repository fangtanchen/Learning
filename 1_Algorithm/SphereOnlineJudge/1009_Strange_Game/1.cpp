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
const int MAXN=10005;

int T,N,K,L,M;
int primelist[MAXN];
bool isPrime[MAXN];
int cnt_prime;


void CreatePrimeList(){
    cnt_prime=0;
    memset(isPrime,true,sizeof(isPrime));
    for(int ni=2;ni<MAXN;ni++){
        if(isPrime[ni]){
            primelist[cnt_prime++]=ni;
        }
        for(int pi=0;pi<cnt_prime;pi++){
            int tmp=primelist[pi]*ni;
            if(tmp>=MAXN)break;
            isPrime[tmp]=false;
            if(ni%primelist[pi]==0)break;
        }
    }
}

int ModExp(int a,int b,int p){
    int ret=1;
    a%=p;
    while(b){
        if(b&0x1){
            ret=(ret*a)%p;
        }
        a=(a*a)%p;
        b>>=1;
    }
    return ret;
}

int getp(int n,int p){
    int ret=0;
    while(n){
        n/=p;
        ret+=n;
    }
    return ret;
}


int f[MAXN];
void CreateFlist(int p,int pk){
    f[0]=1;
    for(int i=1;i<pk;i++){
        if(i%p==0){
            f[i]=f[i-1];
        }else{
            f[i]=(f[i-1]*i)%pk;
        }
    }
}

int F(int n,int p){
    return ModExp(f[p-1],n/p,p)*f[n%p]%p;
}

int Cal(int n,int p,int pk){
    if(n<=1)return 1;
    return F(n,pk)*Cal(n/p,p,pk)%pk;// n may be bigger than pk
}

int extend_gcd(int A,int B,int &x,int &y){
    if(B==0){
        x=1;
        y=0;
        return A;
    }
    int tx,ty;
    int ret=extend_gcd(B,A%B,tx,ty);
    x=ty;
    y=tx-A/B*ty;
    return ret;
}

int China(int m[],int r[],int num){
    int tmpM=m[0] ,tmpR=r[0];
    for(int i=1;i<num;i++){
        int x,y;
        int A,B,C,D;
        A=tmpM,B=m[i],C=r[i]-tmpR;
        int d=extend_gcd(A,B,x,y);
        A/=d;B/=d;C/=d;
        x=(x*C)%B;
        tmpR=(tmpM*x+tmpR);
        tmpM=A*B*d;
    }
    if(tmpR<0)tmpR+=tmpM;
    return tmpR;
}

int Inverse(int k,int p){
    int x,y;
    int d=extend_gcd(k,p,x,y);
    x=(x%p+p)%p;
    if(d==1)return x;
    return -1;
}

int C(int n,int m,int p,int pk){
    int nump=getp(n,p)-getp(m,p)-getp(n-m,p);
    int numk=1;
    int tmp=p;
    while(tmp!=pk){
         tmp*=p;
         numk++;
    }
    if(nump>=numk)return 0;
    int p_n=1;
    for(int i=0;i<nump;i++){
         p_n*=p;
    }
    int pk_n=pk/p_n;
    CreateFlist(p,pk);
    int factor_n=Cal(n,p,pk);
    int factor_m=Cal(m,p,pk);
    int factor_mn=Cal(n-m,p,pk);
    int ans=factor_n*Inverse(factor_m,pk)%pk*Inverse(factor_mn,pk)%pk*p_n%pk;
    return ans;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    CreatePrimeList();
    for(int casei=1;casei<=T;casei++){
         scanf("%d%d%d%d",&N,&K,&L,&M);
         if(M==0){
              printf("Case %d: %d\n",casei,ModExp(K,L,N)+1);
              continue;
         }
         int ans=1;
         if(K&0x01){
             ans=((K-1)/2)%N*ModExp(K,L,N)%N*ModExp(K-1,M-1,N)%N;
         }else{
             ans=(K/2)%N*ModExp(K,L-1,N)%N*ModExp(K-1,M,N)%N;
         }
         int m[20],r[20],cntm=0;
         int tmpN=N;
         for(int pi=0;pi<cnt_prime;pi++){
              if(primelist[pi]*primelist[pi]>tmpN)break;
              if(0==tmpN%primelist[pi]){
                  m[cntm]=1;
                  while(0==tmpN%primelist[pi]){
                       tmpN/=primelist[pi];
                       m[cntm]*=primelist[pi];
                  }
                  r[cntm]=C(L,M,primelist[pi],m[cntm]);
                  cntm++;
              }
         }
         if(tmpN!=1){
              m[cntm]=tmpN;
              r[cntm]=C(L,M,tmpN,m[cntm]);
              cntm++;
         }
         ans=ans*China(m,r,cntm)%N;
         printf("Case %d: %d\n",casei,ans+1);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
