#include <cstdio>
 #include <iostream>
 using namespace std;
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
 inline bool equal1(double a,double b){
	 if((a-b)>-0.0000001&&(a-b)<0.0000001) return true;
	 else return false;}
 int main(){
	 double sum=0.0,d,newx,newy;
	 double mh=43200.0000/11;
	 double sm=3600.0000/59;
	 double sh=43200.0000/719;
	 double dsm,dsh,dmh,tdsm,tdsh,tdmh;
	 while(scanf("%lf",&d)&&d!=-1){
		 sum=0.0;
		   dsm=	10.0*d/59.0;  tdsm=sm-dsm;
		   dsh=	120.0*d/719.0;	 tdsh=sh-dsh;
		   dmh=	120.0*d/11.0;	 tdmh=mh-dmh;
		   newx=max1(dsm,dsh,dmh); newy=min1(tdsm,tdsh,tdmh);
		   while(newx<=43200&&newy<=43200){
			   newx=max1(dsm,dsh,dmh);  		
			   newy=min1(tdsm,tdsh,tdmh);   	//cout<<newx<<" "<<newy; Sleep(1000);
			   if(newx<newy) sum+=newy-newx; //cout<<" "<<sum<<" ";Sleep(1000);
			   if(newy==tdsm) {dsm+=sm;tdsm+=sm;}
			   else if(newy==tdsh) {dsh+=sh;tdsh+=sh;}
			   else if(newy==tdmh){dmh+=mh;tdmh+=mh;}
		   }
		   printf("%.3lf\n",sum/432);}
		   return 0;
 }
