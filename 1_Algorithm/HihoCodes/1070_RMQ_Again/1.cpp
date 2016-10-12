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
const int MAXN=10010;

int weight[MAXN];
int N,Q;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",weight+i);
    }
    int op,l,r,p,d;
    scanf("%d",&Q);
                int ans;
    for(int i=0;i<Q;i++){
        scanf("%d",&op);
        switch(op){
            case 0:
                scanf("%d%d",&l,&r);
                ans=weight[r];
                for(int i=l;i<r;i++){
                    if(weight[i]<ans) ans=weight[i];
                }
                printf("%d\n",ans);
                break;
            case 1:
                scanf("%d%d",&p,&d);
                weight[p]=d;
                break;
        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
