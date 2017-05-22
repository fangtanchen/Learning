#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;

int A[MAXN],B[MAXN],C[MAXN];
int N,M,L;


int FindSmall(int a[],int l,int r,int key){
    if(key<a[l])return -1;
    if(key>=a[r])return a[r];
    while(l+1<r){
        int mid=(l+r)/2;
        if(a[mid]<=key){
             l=mid;
        }else{
            r=mid;
        }
    }
    return a[l];
}
int FindBig(int a[],int l,int r,int key){
     if(key<=a[l])return a[l];
     if(key>a[l])return -1;
     while(l+1<r){
         int mid=(l+r)/2;
         if(a[mid]>=key){
             r=mid;
         }else{
              l=mid;
         }
     }
     return a[r];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M>>L;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    for(int i=1;i<=M;i++){
        cin>>B[i];
    }
    for(int i=1;i<=L;i++){
        cin>>C[i];
    }
    sort(A,A+N);
    sort(B,B+M);
    sort(C,C+L);
    int ans=0x5f5f5f5f;
    for(int i=1;i<=N;i++){
         int bmi=FindSmall(B,1,M,A[i]);
         int bma=FindBig(B,1,M,A[i]);
         int cmi=FindSmall(C,1,L,A[i]);
         int cma=FindBig(C,1,L,A[i]);
         if(bmi!=-1&&cma!=-1){
              ans=min(cma-bmi,ans);
         }
         if(cmi!=-1&&bma!=-1){
              ans=min(bma-cmi,ans);
         }
         if(bmi!=-1&&cmi!=-1){
             int tmp=min(cmi,bmi);
             ans=min(A[i]-tmp,ans);
         }
         if(bma!=-1&&cma!=-1){
              int tmp=max(bma,cma);
              ans=min(tmp-A[i],ans);
         }
    }
    cout<<2*ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
