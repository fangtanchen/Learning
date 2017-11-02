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
const int MAXN=1e6+10;

int N,M,T,K1,K2;
int A[MAXN],B[MAXN];


int Solve(int energy){
    int ret=0;
    for(int i=1;i<N;i++){
        int tmp=(B[i]-A[i])*K1;
        if(energy<tmp){
            ret++;
            energy=M;
        }
        energy-=tmp;
        int kktt=(A[(i+1)]-B[i])*K2;
        if(energy<kktt){
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N>>M>>T>>K1>>K2;
    bool flag=true;
    int sum=0;
    A[0]=B[0]=0;
    for(int i=1;i<=N;i++){
         cin>>A[i]>>B[i];
         int tmp=(B[i]-A[i])*K1;
         if(tmp>M)flag=false;
         sum=sum+(A[i]-B[i-1])*K2+tmp;
    }
    sum=sum+(T-B[N])*K2;
    int ans=(sum+M-1)/M;
    if(!flag){
        cout<<-1<<endl;
        return 0;
    }
    int l=(B[1]-A[1])*K1;
    int r=M;
    int cntl=Solve(l);
    int cntr=Solve(r);
    cout<<min(cntl,cntr)<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
