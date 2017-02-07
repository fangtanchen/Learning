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
const int MAXM=110;

int a[MAXM];
int M;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&M),M){
            int sum=0;
            for(int i=0;i<M;i++){
                scanf("%d",a+i);
                sum^=a[i];
            }
            int cnt=0;
            if(sum){
                 for(int i=0;i<M;i++){
                     if((sum^a[i])<=a[i])cnt++;
                 }
            }
            printf("%d\n",cnt);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
