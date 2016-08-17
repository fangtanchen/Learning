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
const int MAXX=1e5+10;

double Square(double x,double y){
    return x*x+y*y;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    double a,b,r;
    cin>>a>>b>>r;
    int xmax=floor(a+r);
    int xmin=ceil(a-r);
    int ansx=a,ansy=b;
    double max_square=0;
    for(int x=xmax;x>=xmin;x--){
        double k=x-a;
        double tmp=sqrt(r*r-k*k);
        int ymax=floor(b+tmp);
        int ymin=ceil(b-tmp);
        if(ymax<ymin)continue;

        double temp_square=Square(x-a,ymax-b);
        if(temp_square>max_square){
             max_square=temp_square;
             ansx=x;
             ansy=ymax;
        }

        temp_square=Square(x-a,ymin-b);
        if(temp_square>max_square){
             max_square=temp_square;
             ansx=x;
             ansy=ymin;
        }
    }

    cout<<ansx<<" "<<ansy<<endl;
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
