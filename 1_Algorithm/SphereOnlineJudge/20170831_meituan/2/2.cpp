#include<iostream>

using namespace std;

const int MAXN=40;

int N;
int s[MAXN];

int main(){
    scanf("%d",&N);
    int maxs=0,sum=0;
    for(int i=1;i<=N;i++){
        scanf("%d",s+i);
        maxs=max(maxs,s[i]);
        sum+=s[i];
    }
    if(maxs>sum-maxs){
        printf("No\n");
    }else{
        printf("Yes\n");
    }

    return 0;
}
