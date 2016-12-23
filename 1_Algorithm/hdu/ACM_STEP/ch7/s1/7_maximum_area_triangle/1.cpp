#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<utility>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=5e4+10;
typedef pair<double,double> pdd;

pdd pt[MAXN];
pdd st[MAXN];
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
        while(EOF!=scanf("%d",&N)){
            int mini=0;
            for(int ni=0;ni<N;ni++){
                scanf("%lf%lf",&pt[ni].first,&pt[ni].second);
                if(pt[ni].second<pt[mini].second)mini=ni;
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
            for(int i=0;i<stlen;i++){
                for(int j=i+1;j<stlen;j++){
                    for(int k=j+1;k<=stlen;k++){
                        double tmp=Direction(st[i],st[j],st[k]);
                        if(tmp<0)tmp*=-1;
                        ans=max(ans,tmp);
                    }
                }
            }
            printf("%.2lf\n",ans/2);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
