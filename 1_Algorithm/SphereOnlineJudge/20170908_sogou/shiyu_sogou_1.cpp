#include<iostream>
#include<cstdio>
#include<cmath>


using namespace std;

int n;
double num[2000010];


double BinarySearch(double *arr,int count,double key){
    int lpos=0,rpos=2*count-1;
    double findval=key+180.0;
    while(lpos<=rpos){
        int mid=(lpos+rpos)/2;
        if(fabs(arr[mid]-findval)<1e-8)return 180;
        else if(arr[mid]>findval)rpos=mid-1;
        else lpos=mid+1;
    }
    double ret1=360-arr[lpos]+key;
    double ret2=arr[rpos]-key;
    return max(ret1,ret2);
}

int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%lf",num+i);
    }
    for(int i=0;i<n;i++){
        num[i+n]=num[i]+360;
    }
    double ret=0;
    for(int i=0;i<n;i++){
        double dist=BinarySearch(num,2*n,num[i]);
        if(dist>ret)ret=dist;
    }
    printf("%.8lf\n",ret);

    return 0;
}
