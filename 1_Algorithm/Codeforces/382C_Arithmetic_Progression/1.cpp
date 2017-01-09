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
const int MAXN=1e5+10;

int d[MAXN];
int num[MAXN];
int N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    for(int ni=0;ni<N;ni++){
         scanf("%d",num+ni);
    }
    if(N==1){
        printf("-1\n");
        return 0;
    }
    sort(num,num+N);
    if(N==2){
        int tmp=num[1]-num[0];
        if(tmp==0){
            printf("1\n%d\n",num[0]);
            return 0;
        }
        if((tmp>=1)&&((tmp&0x1)==0))printf("3\n");
        else printf("2\n");
        printf("%d",2*num[0]-num[1]);
        if((tmp>=1)&&((tmp&0x1)==0))printf(" %d",(num[0]+num[1])>>1);
        printf(" %d\n",2*num[1]-num[0]);
        return 0;
    }
    int imax=N-1;
    for(int i=0;i<imax;i++){
         d[i]=num[i+1]-num[i];
    }
    sort(d,d+imax);
    int cnt=0;
    int ud[10];
    ud[cnt++]=d[0];
    for(int i=1;i<imax;i++){
        if(d[i]!=d[i-1]){
            ud[cnt++]=d[i];
            if(cnt>2)break;
        }
    }
    int nans=0;
    int ans[10];
    if(cnt==1){
       nans=2;
       ans[0]=num[0]-ud[0];
       ans[1]=num[N-1]+ud[0];
       if(ans[0]==ans[1])nans--;
    }else if(2==cnt){
        if(ud[1]==2*ud[0]){
            int tt=0;
            for(int i=0;i<imax;i++){
                if(num[i+1]-num[i]==ud[1]){
                    ans[nans++]=((num[i+1]+num[i])>>1);
                    tt++;
                    if(tt>1)break;
                }
            }
            if(tt>1)nans=0;
        }
    }
    printf("%d\n",nans);
    if(nans>0){
        printf("%d",ans[0]);
        for(int i=1;i<nans;i++){
            printf(" %d",ans[i]);
        }
        printf("\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
