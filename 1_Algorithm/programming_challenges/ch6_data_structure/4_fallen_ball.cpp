#include<stdio.h>
#include<string.h>
const int MAXD=20;
int s[1<<MAXD];

int main(){
    int D,I;
    while(2==scanf("%d%d",&D,&I)){
        memset(s,0,sizeof(s));
        int k,n=(1<<D)-1;
        for(int i=0;i<I;i++){
            k=1;
            while(k<=n){
                s[k]=!s[k];
                k=s[k]?2*k:2*k+1;
            }
        }
        printf("%d\n",k/2);
    }
    return 0;
}
