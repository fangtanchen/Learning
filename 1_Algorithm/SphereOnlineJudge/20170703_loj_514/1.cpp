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
const int MAXN=10005;
const int MAXM=1e5+10;

int A[MAXN];
int N,M;
int f[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    for(int i=0;i<N;i++){
         cin>>A[i];
    }
    memset(f,0x80,sizeof(f));
    for(int i=0;i<N;i++){
        int tmp=0;
        for(int j=i;j<N;j++){
            tmp+=A[j];
            f[j-i+1]=max(f[j-i+1],tmp);
        }
    }
    for(int i=N-1;i>=1;i--){
         f[i]=max(f[i+1],f[i]);
    }
    while(M--){
         int x;
         cin>>x;
         cout<<f[x]<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
