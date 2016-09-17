#include<iostream>
#include<cstdio>
#include<algorithm>


using namespace std;
#define MAXN 1000009

typedef long long int ll;

int N;
int hill[MAXN];
int tmp[MAXN];


int main(){

    cin>>N;
    for(int i=1;i<=N;i++){
         cin>>hill[i];
         tmp[i]=hill[i];
    }
    sort(tmp,tmp+N);
    ll all=N*(N-1)/2;
    for(int i=1;i<=N;i++){
         int mid=(N+1)/2;
         int l=1;
         int r=N;
         while(tmp[mid]!=hill[i]){
             if(tmp[mid]<hill[i]){
                 l=mid+1;
             }else{
                 r=mid-1;
             }
             mid=(l+r)/2;
         }
         while((mid>=1)&&(tmp[mid]==hill[i])){
              mid--;
         }
         all=all-(mid*(mid-1))/2;
    }
    cout<<all<<endl;



    return 0;
}

