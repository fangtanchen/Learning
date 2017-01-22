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
const int MAXN=1005;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int A,B;
    while(EOF!=scanf("%d%d",&A,&B)){
        int ans=0;
        while(A){
            int d1=A%10;
            int tmpB=B;
            while(tmpB){
                int d2=tmpB%10;
                ans+=d1*d2;
                tmpB/=10;
            }
            A/=10;
        }
        printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
