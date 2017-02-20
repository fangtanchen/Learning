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
const int MAXN=2e5+10;

int A[MAXN],N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(int i=1;i<=N;i++)
        scanf("%d",A+i);
    for(int i=1;i<=N-i+1;i++){
         if(1&i)swap(A[i],A[N-i+1]);
    }
    for(int i=1;i<=N;i++)
        printf("%d ",A[i]);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
