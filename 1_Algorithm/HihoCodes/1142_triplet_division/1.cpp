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
#define DIST(A,B,C,X,Y,x) sqrt(pow((X)-(x),2)+(pow((Y)-((A)*(x)*(x)+(B)*(x)+(C)),2)))



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    double a,b,c,x,y;
    double l,lm,r,rm;
    cin>>a>>b>>c>>x>>y;
    double mid=-b/(2*a);

/*    if(mid<x){
        l=mid;
        r=mid+500;
        }else{
        r=mid;
        l=mid-500;
        }*/
    l=-500;r=500;

    while(r-l>1e-4){
        lm=l+(r-l)/3;
        rm=r-(r-l)/3;
        if(DIST(a,b,c,x,y,lm)<DIST(a,b,c,x,y,rm)){
            r=rm;
        }else{
            l=lm;
        }
    }
    printf("%.3lf\n",DIST(a,b,c,x,y,(l+r)/2));


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
