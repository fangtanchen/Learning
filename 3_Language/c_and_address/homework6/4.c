#include<stdio.h>

void Move(int *A,int n,int m){
    for(int i=m;i<n;i++){
        int jmin=i-m;
        for(int j=i-1;j>=jmin;j--){
            int tmp=*(A+j);
            *(A+j)=*(A+j+1);
            *(A+j+1)=tmp;
        }
    }
}

int main(){
    int A[100]={1,2,3,4,5,6,7,8,9,10};
    int n,m=3;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",A+i);
    }
    Move(A,n,m);
    for(int i=0;i<n;i++){
        printf("%d ",A[i]);
    }

    return 0;
}
