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
typedef long long int LL;
const int MAXN=1e5+10;


LL A[MAXN],B[MAXN];
LL sumA,sumB;
int N,M;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>M>>N;
    for(int i=0;i<M;i++)cin>>A[i],sumA+=A[i];
    for(int i=0;i<N;i++)cin>>B[i],sumB+=B[i];
    sort(A,A+M);
    sort(B,B+N);
    LL t1=sumB+sumA-max(A[M-1],B[N-1]);
    LL t2=0;
    for(int i=0,j=0;i<M&&j<N;){
        if(A[i]<B[j]||(A[i]==B[j]&&(N-j<M-i))){
            t2+=min((A[i])*(N-j),A[i]);
            i++;
        }else{
            t2+=min(B[j],B[j]*(M-i));
            j++;
        }
    }
    cout<<min(t1,t2)<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
