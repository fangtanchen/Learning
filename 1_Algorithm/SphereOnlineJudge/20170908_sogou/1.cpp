#include<iostream>
#include<cstdio>


using namespace std;
const int MAXN=2e6+10;

int N;
double A[MAXN];

int main(){
    scanf("%d",&N);
    for(int i=0;i<N;i++){
        scanf("%lf",A+i);
        A[i+N]=A[i]+360;
    }
    double ans=0;
    int imax=2*N;
    for(int i=0;i<N;i++){
        double tmp=(A[i]+180);
        //if(tmp>=360)tmp-=360;
        int lpos,rpos;
        //  找第一个大于tmp的数
        int l=0,r=2*N-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(A[mid]>tmp)r=mid-1;
            else l=mid+1;
        }
        double kk=max(360-A[l]+A[i],A[r]-A[i]);
        ans=max(kk,ans);
    }
    printf("%.8lf\n",ans);

    return 0;
}
