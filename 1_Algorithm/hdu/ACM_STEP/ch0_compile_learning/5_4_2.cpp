#include<stdio.h>
#include<string.h>
#include<math.h>

#define FOR(i,a,b) for(int i=a;i<b;i++)

int is_prime(int n){
    int imax=sqrt(n)+1;
    for(int i=2;i<imax;i++){
        if(n%i==0)return 0;
    }
    return 1;
}

int main(){
    int prime[100],len_prime=0;
    int p[100],n;
    FOR(i,2,101){
         if(is_prime(i))
             prime[len_prime++]=i;
    }
    while(1==scanf("%d",&n)){
         printf("%d! =",n);
         memset(p,0,sizeof(p));
         int maxp=0;
         int imax=n+1;
         FOR(i,1,imax){
              int m=i;
              FOR(j,0,len_prime){
                  while(m%prime[j]==0){
                      m/=prime[j];
                      p[j]++;
                      if(j>maxp)maxp=j;
                  }
              }
         }
        FOR(i,0,maxp+1)
            printf(" %d",p[i]);
        printf("\n");
    }
    return 0;


}
