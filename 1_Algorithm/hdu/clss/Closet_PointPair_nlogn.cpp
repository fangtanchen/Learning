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
const int MAXN=1e5+20;
const int INF=0x3f3f3f3f;
typedef pair<double,double> pdd;

pdd X[MAXN],Y[MAXN];
int N;

bool CmpX(pdd p1,pdd p2){
    if(p1.first<p2.first)return true;
    else if((p1.first==p2.first)&&(p1.second<=p2.second))
        return true;
    return false;
}

bool CmpY(pdd p1,pdd p2){
    if(p1.second<p2.second)return true;
    else if((p1.second==p2.second)&&(p1.first<=p2.first))
        return true;
    return false;
}

double Dist(pdd p1,pdd p2){
     return (p1.first-p2.first)*(p1.first-p2.first)
         +(p1.second-p2.second)*(p1.second-p2.second);
}

double Solve(pdd *X,pdd *Y,int num){
    if(num<=3){
        double ret=INF;
        for(int i=0;i<num;i++){
            for(int j=i+1;j<num;j++){
                ret=min(ret,Dist(X[i],X[j]));
            }
        }
        return ret;
    }
    int lnum=num/2;
    if((X[lnum-1].first==X[lnum].first)
            &&(X[lnum-1].second==X[lnum].second))
        return 0;
    int rnum=num-lnum;
    pdd *Yl=new pdd[lnum];
    pdd *Yr=new pdd[rnum];
    int yllen=0,yrlen=0;
    for(int i=0;i<num;i++){
        if(CmpX(Y[i],X[lnum-1])){
            Yl[yllen++]=Y[i];
        }else{
            Yr[yrlen++]=Y[i];
        }
    }
    double ret1=Solve(X,Yl,lnum);
    double ret2=Solve(X+lnum,Yr,rnum);
    double ret=min(ret1,ret2);
    delete[] Yl;
    delete[] Yr;
    int l=0,r=num-1;
    double lbord=X[lnum-1].first-ret;
    double rbord=X[lnum-1].first+ret;
    pdd *tmpY=new pdd[num];
    int tmplen=0;
    for(int i=0;i<num;i++){
        if((Y[i].first>=lbord)&&(Y[i].first<=rbord)){
            tmpY[tmplen++]=Y[i];
        }
    }
    for(int i=0;i<tmplen;i++){
        for(int j=1;j<=7;j++){
            if(i+j>=tmplen)break;
            ret=min(ret,Dist(tmpY[i],tmpY[i+j]));
        }
    }
    delete[] tmpY;
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
        while((EOF!=scanf("%d",&N))&&N){
            for(int ni=0;ni<N;ni++){
                scanf("%lf%lf",&X[ni].first,&X[ni].second);
            }
            memcpy(Y,X,sizeof(X));
            sort(X,X+N,CmpX);
            sort(Y,Y+N,CmpY);
            double ans=Solve(X,Y,N);
            printf("%.2lf\n",sqrt(ans)/2);
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
