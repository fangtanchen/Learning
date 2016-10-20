#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cstdlib>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;


int M;
int num[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&M),M){
            int res=0;
            for(int i=1;i<=M;i++){
                scanf("%d",num+i);
                res^=num[i];
            }
            if(!res)printf("0\n");
            else{
                int ans=0;
                for(int i=1;i<=M;i++){
                    if((res^num[i])<num[i]){
                        ans++;
                    }
                }
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
