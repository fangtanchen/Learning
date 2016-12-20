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
typedef pair<double,double > pii;
const int MAXN=1e6+10;


pii pt[MAXN];
int T,N;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int ni=0;ni<N;ni++){
            scanf("%lf%lf",&pt[ni].first,&pt[ni].second);
        }
        pii p0(0,0);
        double totalarea=0;
        double gx,gy;
        gx=gy=0;
        for(int i=0;i<N;i++){
            int a=i,b=(i+1)%N;
            double area=pt[a].first*pt[b].second
                -pt[a].second*pt[b].first;
            totalarea+=area;
            gx=gx+(pt[a].first+pt[b].first)*area;
            gy=gy+(pt[a].second+pt[b].second)*area;
        }
        gx=gx/3/totalarea;
        gy=gy/3/totalarea;
        printf("%.2lf %.2lf\n",gx,gy);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
