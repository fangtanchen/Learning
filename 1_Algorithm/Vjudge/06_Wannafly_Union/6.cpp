#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;


double dist[MAXN][MAXN];
int w,h,n;
double x[MAXN],y[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>w>>h>>n;
    for(int i=1;i<=n;i++){
         cin>>x[i]>>y[i];
         dist[i][i]=0x3f3f3f3f;
    }
    double ans=0;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            dist[i][j]=dist[j][i]
                =sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
        }
        sort(dist[i]+1,dist[i]+n+1);
        ans=max(ans,dist[i][2]);
    }
    printf("%.13lf\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
