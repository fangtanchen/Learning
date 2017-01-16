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
const int INF=0x3f3f3f3f;

int hy,ay,dy;
int hm,am,dm;
int h,a,d;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d%d",&hy,&ay,&dy);
    scanf("%d%d%d",&hm,&am,&dm);
    scanf("%d%d%d",&h,&a,&d);
    int ans=INF;
    int amax=dm+hm+2;
    amax=max(amax,100);
    for(int ai=max(ay,dm+1);ai<=amax;ai++){
        for(int di=dy;di<=100;di++){
            int tmp=a*(ai-ay)+d*(di-dy);
            if(am>di){
                int hi=(hm+ai-dm-1)/(ai-dm)*(am-di);
                if(hi>=hy)tmp+=(h*(hi-hy+1));
            }
            ans=min(tmp,ans);
        }
    }
    printf("%d\n",ans);

	#ifdef L_JUDGE
//		system("out.txt");
		fclose(stdin);
		fclose(stdout);
	#endif

	return 0;
}
