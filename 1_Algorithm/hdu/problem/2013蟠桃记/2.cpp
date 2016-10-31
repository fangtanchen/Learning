#include<stdio.h>
#include<math.h>


int main(){
    for(int i=1;i<=1000;i++){
        int sum=0;
        int jmax=i/2;
        for(int j=1;j<=jmax;j++){
            if(i%j==0){
                sum+=j;
            }
        }
        if(i==sum){
             printf("%d\n",i);
        }
    }

}
