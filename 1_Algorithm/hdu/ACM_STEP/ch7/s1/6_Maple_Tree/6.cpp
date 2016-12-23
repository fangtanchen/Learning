#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define dist(x,y) sqrt(((x.first-y.first)*(x.first-y.first))+((x.second-y.second)*(x.second-y.second)))
typedef pair<double,double> pdd;

const int MAXN=110;
pdd st[MAXN*2],pt[MAXN];
int stlen,N;

double Direction(pdd p0,pdd p1,pdd p2){
     return (p2.first-p0.first)*(p1.second-p0.second)
         -(p2.second-p0.second)*(p1.first-p0.first);
}

bool Cmp(pdd p1,pdd p2){
    return Direction(pt[0],p1,p2)<=0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            int mini=0;
            for(int ni=0;ni<N;ni++){
                scanf("%lf%lf",&pt[ni].first,&pt[ni].second);
                if(pt[ni].second<pt[mini].second)mini=ni;
            }
            if(1==N){
                 printf("%.2lf\n",0.5);
                 continue;
            }
            if(2==N){
                printf("%.2lf\n",dist(pt[0],pt[1])/2+0.5);
                continue;
            }
            swap(pt[0],pt[mini]);
            sort(pt+1,pt+N,Cmp);

            stlen=-1;
            st[++stlen]=pt[0];
            st[++stlen]=pt[1];
            st[++stlen]=pt[2];
            for(int ni=3;ni<N;ni++){
                 pdd p0=st[stlen-1];
                 pdd p1=st[stlen];
                 pdd p2=pt[ni];
                 while(Direction(p0,p1,p2)>=0){
                     stlen--;
                     p0=st[stlen-1];
                     p1=st[stlen];
                 }
                 st[++stlen]=p2;
            }
            double ans=0;
            for(int i=0;i<=stlen;i++){
                for(int j=i+1;j<=stlen;j++){
                    for(int k=j+1;k<=stlen;k++){
                        double a=dist(st[i],st[j]);
                        double b=dist(st[i],st[k]);
                        double c=dist(st[j],st[k]);
                        double r;
                        if((a*a+b*b<c*c)
                                ||(a*a+c*c<b*b)
                                ||(b*b+c*c<a*a)){
                            r=max(max(a,b),c);
                        }else{
                            double S=fabs(Direction(st[i],st[j],st[k]));
                            r=a*b*c/(S);
                        }
                        ans=max(ans,r);
                    }
                }
            }
            printf("%.2lf\n",ans/2+0.5);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
