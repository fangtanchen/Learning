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
    scanf("%d%d",&k,&m);
    int a[11];
    printf("%-10d:",10);
    for(int i=0;i<10;i++){
         scanf("%d",kk[10]+i);
         a[i]=kk[10][i];
         printf("%5d",kk[10][i]);
    }
    printf("\n");
    memset(kk,0,sizeof(kk));
    for(int i=0;i<10;i++){
        printf("%-10d:",i);
        kk[i][i]=1;
        for(int j=0;j<10;j++){
            printf("%5d",kk[i][j]);
        }
        printf("\n");
    }
    for(int i=10;i<110;i++){
        printf("%-10d:",i);
        for(int j=0;j<10;j++){
            for(int k=0;k<10;k++){
                kk[i][j]+=a[k]*kk[i-k-1][j];
            }
            kk[i][j]%=m;
            printf("%5d",kk[i][j]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
