#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
typedef pair<double,double> pdd;

double A[MAXN],B[MAXN];
int Q,N;


bool cmp(int x,int y){
    return B[x]>B[y];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&Q);
    while(Q--){
         scanf("%d",&N);
         for(int ni=0;ni<N;ni++){
             scanf("%lf%lf",A+ni,B+ni);
         }
         sort(A,A+N,cmp);
         sort(B,B+N);
         double sum=0;
         bool flag=false;
         for(int i=0;i<N;i++){
             if(flag)break;
             for(int j=i+1;j<N;j++){
                 if(flag)break;
                 double tmp=A[i]+A[j];
                 for(int k=j+1;k<N;k++){
                     if(flag)break;
                     double pp=tmp+A[k];
                     if(fmod(pp,5.0)<1e-6){
                          sum=B[i]+B[j]+B[k];
                          flag=true;
                     }
                 }
             }
         }
         printf("%d\n",(int)sum);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
