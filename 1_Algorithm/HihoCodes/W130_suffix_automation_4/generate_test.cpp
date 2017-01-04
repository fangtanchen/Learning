#include<cstdio>
#include<cstdlib>
#include<ctime>

int main(){
    freopen("in.txt","w",stdout);
    srand(time(NULL));
    int N=rand()%50;
    printf("%d\n",N);
    for(int i=0;i<N;i++){
        int len=rand()%500;
        for(int j=0;j<len;j++){
            printf("%d",rand()%10);
        }
        printf("\n");
    }
    fclose(stdout);
    return 0;
}
