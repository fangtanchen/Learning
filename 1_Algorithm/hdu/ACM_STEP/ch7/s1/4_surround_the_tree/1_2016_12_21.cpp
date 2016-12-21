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
const int MAXN=200;

typedef pair<double,double> pdd;

pdd pt[MAXN];
pdd p0;
pdd st[MAXN*10];
int stlen;
int N;

double Direction(pdd p0,pdd p1,pdd p2){
    return (p2.first-p0.first)*(p1.second-p0.second)
        -(p2.second-p0.second)*(p1.first-p0.first);
}

bool Cmp(pdd p1,pdd p2){
    return Direction(pt[0],p1,p2)<0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(scanf("%d",&N),N){
            int mini=0;
            for(int ni=0;ni<N;ni++){
                scanf("%lf%lf",&pt[ni].first,&pt[ni].second);
                if(pt[ni].second<pt[mini].second)mini=ni;
            }
            if(1==N){
                printf("0.00\n");
                continue;
            }
            if(2==N){

                double ans=sqrt((pt[0].first-pt[1].first)*(pt[0].first-pt[1].first)
                        +(pt[0].second-pt[1].second)*(pt[0].second-pt[1].second));
                printf("%.2lf\n",ans);
                continue;
            }
            swap(pt[mini],pt[0]);
            sort(pt+1,pt+N,Cmp);

            stlen=-1;
            st[++stlen]=pt[0];
            st[++stlen]=pt[1];
            for(int ni=2;ni<N;ni++){
                pdd p0=st[stlen-1];
                pdd p1=st[stlen];
                pdd p2=pt[ni];
                while(Direction(p0,p1,p2)>=0){
                    stlen--;
                    if(stlen==0)break;
                    p0=st[stlen-1];
                    p1=st[stlen];
                }
                st[++stlen]=p2;
            }
            double ans=0;
            stlen++;
            for(int i=0;i<stlen;i++){
                int j=(i+1)%stlen;
                ans+=sqrt((st[i].first-st[j].first)*(st[i].first-st[j].first)
                        +(st[i].second-st[j].second)*(st[i].second-st[j].second));
            }
            printf("%.2lf\n",ans);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
