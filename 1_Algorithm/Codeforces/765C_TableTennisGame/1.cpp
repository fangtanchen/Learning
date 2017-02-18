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

int k,a,b;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int ans=0;
    scanf("%d%d%d",&k,&a,&b);
    int al=a/k,bl=b/k;
    int am=a%k,bm=b%k;
    ans=a/k+b/k;
    if(al==0){
        if(bl==0){
            if(am==0 && bm==0)printf("0\n");
            else printf("-1\n");
        }else{
            if(bm==0)printf("%d\n",ans);
            else printf("-1\n");
        }
    }else{
        if(bl==0){
            if(am==0)printf("%d\n",ans);
            else printf("-1\n");
        }else{
            printf("%d\n",ans);
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
