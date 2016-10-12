#include<stdio.h>

int main(){
    int n;
    int a[10000],i,j,tmp;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        a[i]=i;
    }

    for(i=1;i<=n;i++){
        if(1==i){
            a[1]=0;
        }else{
            for(j=2;j<i;j++){
                int tmp=a[i]%j;
                if(0==tmp){
                    a[i]=0;
                    break;
                }
            }
        }
    }

    int cnt=1;
    for(i=1;i<=n;i++){
        if(0!=a[i]){
            printf("%5d ",a[i]);
            cnt++;
        }
        if(cnt%10==0){
            printf("\n");
            cnt=1;
        }
    }
    printf("\n");


    return 0;
}
