#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
 double max1(double a,double b,double c){
	 if(a<b) a=b;
	 if(a<c) a=c;
	 return a;
 }
 double min1(double a,double b,double c){
	 if(a>b) a=b;
	 if(a>c) a=c;
	 return a;
 }
int main(int argc, char *argv[]) {
	double sum=0.0;
	double tempx=0.0;
	double tempy=0.0;
	double sm;
	double sh;
	double mh;
	double dsm;
	double dsh;
	double dmh;
	double bsm,bsh,bmh;
	double d;
	sm=3600.0/59;
	sh=43200.0/719;
	mh = 43200.0/11;
	while(scanf("%lf",&d)==1&&d!=-1)
	{
		sum=0;
		dsm = sm*d/360;
		dsh = sh*d/360;
		dmh = mh*d/360;
		bsm=sm-dsm;
		bsh=sh-dsh;
		bmh=mh-dmh;
		tempx=max1(dsh,dsm,dmh);
		tempy=min1(bsh,bsm,bmh);	
		while(tempx<=43200&&tempy<=43200)
		{
			tempx=max1(dsh,dsm,dmh);
			tempy=min1(bsh,bsm,bmh);	
			if(tempx<tempy)
			{
				sum+=(tempy-tempx);				
			}
			if(tempy==bsm)
			{
				dsm+=sm;
				bsm+=sm;
			}
			if(tempy==bsh)
			{
				dsh+=sh;
				bsh+=sh;
			}
			if(tempy==bmh)
			{
				dmh+=mh;
				bmh+=mh;
			}			
		}
		printf("%.3lf\n",sum/432);
	}
	return 0;
}
