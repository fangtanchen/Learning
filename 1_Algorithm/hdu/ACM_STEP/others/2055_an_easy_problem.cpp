#include<cstdio>
int k[300];
int main(){
    for(int ki='A',p=1;ki<='Z';ki++,p++){
        k[ki]=p;
    }
    for(int ki='a',p=-1;ki<='z';ki++,p--){
        k[ki]=p;
    }
    int T;
    scanf("%d",&T);
    while(T--){
        char ch;
        int y;
        getchar();
        scanf("%c %d",&ch,&y);
        printf("%d\n",y+k[ch]);
    }


    return 0;
}
