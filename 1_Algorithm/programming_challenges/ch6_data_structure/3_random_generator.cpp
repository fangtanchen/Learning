#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int n=100;
int m=100000;

double random(){
    return (double)rand()/RAND_MAX;
}

int random(int m){
    return (int)(random()*(m-1)+0.5);
}

int main(){
     srand(time(NULL));

     return 0;
}
