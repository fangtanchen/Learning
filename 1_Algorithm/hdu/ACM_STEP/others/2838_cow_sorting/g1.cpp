#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<ctime>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int num[91000] ;

int main(){
	#ifdef L_JUDGE
//		freopen("in.txt","r",stdin);
		freopen("in.txt","w",stdout);
	#endif
    int n=90000;
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
         num[i]=i;
    }
    srand(time(NULL));
    int imax=rand()%10000*10000+rand()%10000;
    for(int i=1;i<=imax;i++){
         next_permutation(num+1,num+n+1);
    }
    for(int i=1;i<=n;i++){
         printf("%d\n",num[i]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
