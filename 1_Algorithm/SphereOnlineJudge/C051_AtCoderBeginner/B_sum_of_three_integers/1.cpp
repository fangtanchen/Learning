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
int K,S;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&K,&S);
    int ans=0;
    for(int ai=0;ai<=K;ai++){
        if(ai+2*K<S)continue;
        for(int bi=0;bi<=K;bi++){
            int ci=S-ai-bi;
            if(ci>K)continue;
            if(ci<0)break;
            ans++;
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
