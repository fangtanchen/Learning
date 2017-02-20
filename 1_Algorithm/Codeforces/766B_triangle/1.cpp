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

int N;
long long int A[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
         scanf("%lld",A+i);
    }
    sort(A+1,A+N+1);
    bool flag=false;
    for(int i=3;i<=N;i++){
        long long int a=A[i-2],b=A[i-1],c=A[i];
        if((a+b>c)&&(a+c>b)&&(b+c>a)){
            flag=true;
             break;
        }
    }
    if(flag)puts("YES");
    else puts("NO");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
