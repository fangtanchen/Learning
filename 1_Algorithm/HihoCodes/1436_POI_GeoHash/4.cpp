#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<vector>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

typedef pair<int,int> pii;

const int MAXN=105;
const int MAXM=105;
const double PI=acos(-1.0);
const char base32[40]="0123456789bcdefghjkmnpqrstuvwxyz";
map<char,int> mp;


int N,M;

void Init(){
    for(int i=0;i<32;i++){
        mp[base32[i]]=i;
    }
}


void Encode(double lat,double lon,int prec,char *ret){
    double lon_in[2]={-PI,PI};
    double lat_in[2]={-PI/2,PI/2};
    int len=5*prec;
    int bits=0;
    int reti=0;
    for(int i=1;i<=len;i++){
        if(i%2){
            double mid=(lon_in[0]+lon_in[1])/2;
            if(lon>mid){
                lon_in[0]=mid;
                bits=bits*2+1;
            }else{
                 lon_in[1]=mid;
                 bits*=2;
            }
        }else{
            double mid=(lat_in[0]+lat_in[1])/2;
            if(lat>mid){
                lat_in[0]=mid;
                bits=bits*2+1;
            }else{
                 lat_in[1]=mid;
                 bits*=2;
            }
        }
        if(i%5==0){
             ret[reti++]=base32[bits];
             bits=0;
        }
    }
    ret[reti]=0;
}

void Decode(char *str,double &lat,double &lon){
    double lon_in[2]={-PI,PI};
    double lat_in[2]={-PI/2,PI/2};
    bool blon=true;
    for(int si=0;str[si];si++){
         int bits=mp[str[si]];
         for(int j=4;j>=0;j--){
             if(blon){
                 double  mid=(lon_in[0]+lon_in[1])/2;
                 if(bits&(1<<j)){
                     lon_in[0]=mid;
                 }else{
                     lon_in[1]=mid;
                 }
             }else{
                 double  mid=(lat_in[0]+lat_in[1])/2;
                 if(bits&(1<<j)){
                     lat_in[0]=mid;
                 }else{
                     lat_in[1]=mid;
                 }
             }
             blon=!blon;
         }
    }
    lat=(lat_in[0]+lat_in[1])/2;
    lon=(lon_in[0]+lon_in[1])/2;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);
    for(int ni=0;ni<N;ni++){
         double lon,lat;
         char ret[20];
         scanf("%lf%lf",&lat,&lon);
         lat=lat/180.0*PI;
         lon=lon/180.0*PI;
         Encode(lat,lon,10,ret);
         printf("%s\n",ret);
    }

    for(int mi=0;mi<M;mi++){
         double lon,lat;
         char str[20];
         scanf("%s",str);
         Decode(str,lat,lon);
         lat=lat/PI*180;
         lon=lon/PI*180;
         printf("%.6lf %.6lf\n",lat,lon);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
