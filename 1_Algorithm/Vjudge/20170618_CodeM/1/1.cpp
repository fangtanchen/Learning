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
const int MAXN=1010;

int n;
double v,u,c[MAXN],d[MAXN];
double t[MAXN];



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>n>>v>>u;
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(int i=1;i<=n;i++){
        cin>>d[i];
    }
    memset(t,0,sizeof(t));
    double ans=0;
    for(int i=1;i<=n;i++){
        double kk=c[i]-v;
        for(int j=0;j<n;j++){
            t[i]=t[i]+u/kk;
             kk-=d[i];
        }
        ans+=t[i];
    }
    printf("%.3lf\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
