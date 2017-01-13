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

int kk[10010][10];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int k,m;
    int a[11];
    scanf("%d%d",&k,&m);
    for(int i=1;i<11;i++){
        scanf("%d",a+i);
        kk[i]=i;
    }
    for(int i=10;i<=10000;i++){
        kk[i]=0;
        for(int j=1;j<=10;j++){
            kk[i]+=a[j]*kk[i-j];
        }

        kk[i]%=m;
        printf("%5d",kk[i]);
        if(i%10==0)printf("\n");
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
