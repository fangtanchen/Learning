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
typedef pair<double,double>  pii;


const int MAXN=105;
const int INF=100000;

pii pt[MAXN];
int N,T;
double U;


double CrossProduct(pii x,pii y,pii z){
    double ret=(x.first-y.first)*(x.second-z.second)
        -(x.second-y.second)*(x.first-z.first);
    if(ret<0)ret=-ret;
    return ret;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif

    scanf("%d",&T);
    while(T--){
         cin>>N>>U;
         for(int i=0;i<N;i++){
             cin>>pt[i].first>>pt[i].second;
         }
         double maxu=0,minu=10000000;
         pii maxpt=make_pair(-INF,-INF),minpt=make_pair(INF,INF);
         for(int i=0;i<N;i++){
             for(int j=i+1;j<N;j++){
                 for(int k=j+1;k<N;k++){
                     double tmp=CrossProduct(pt[i],pt[j],pt[k]);
                     if(tmp<1e-6)continue;
                     double x=(pt[i].first+pt[j].first+pt[k].first)/3;
                     double y=(pt[i].second+pt[j].second+pt[k].second)/3;
                     pii p=make_pair(x,y);
                     if(tmp>=maxu){
                         if(tmp>maxu){
                             maxpt=p;
                         }
                         else{
                             if(p.first>maxpt.first){
                                 maxpt=p;
                             }else if(p.first==maxpt.first
                                     &&p.second>maxpt.second){
                                 maxpt=p;
                             }
                         }
                         maxu=tmp;
                     }
                     if(tmp<=minu){
                         if(tmp<minu){
                             minpt=p;
                         }else{
                             if(p.first<minpt.first){
                                 minpt=p;
                             }else if(p.first==minpt.first
                                     &&p.second<minpt.second){
                                 minpt=p;
                             }
                         }
                         minu=tmp;
                     }
                 }
             }
         }
         double ans=sqrt((maxpt.first-minpt.first)*(maxpt.first-minpt.first)
                 +(maxpt.second-minpt.second)*(maxpt.second-minpt.second))/U;
         printf("%.2lf\n",ans);
    }



	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
