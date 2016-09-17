#include<iostream>
#include<cstdio>
#include<algorithm>


#define MAXN 100000

int tree[MAXN];
int N;

bool init(){
    memset(tree,0,sizeof(tree));
    return true;
}

int lowbit(int k){
    return k&-k;
    //return x&(x^(x-1));
}

bool add(int k, int a){
    while(k<=N){
         tree[k]+=a;
         k+=lowbit(k);
    }
    return true;
}


int sum(int k){
    int res=0;
    while(k>0){
        res+=tree[k];
        k-=lowbit(k);
    }
    return res;
}

int main(){


    return 0;
}

