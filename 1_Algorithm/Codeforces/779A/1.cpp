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

int N;
int A[MAXN],B[MAXN];
int cntA[MAXN],cntB[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>N;
    for(int i=0;i<N;i++)
        scanf("%d",A+i),cntA[A[i]]++;
    for(int i=0;i<N;i++)
        scanf("%d",B+i),cntB[B[i]]++;
    int ans=0;
    bool flag=true;
    int pp=0;
    for(int i=1;i<=5;i++){
        int tmp=cntA[i]-cntB[i];
        if(abs(tmp)&1){
            flag=false;
            break;
        }
        if(tmp>0){
            ans+=tmp/2;
            pp+=tmp/2;
        }else{
            pp+=tmp/2;
        }
    }
    if((flag)&&(pp==0)){
        printf("%d\n",ans);
    }else{
        printf("-1\n") ;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
