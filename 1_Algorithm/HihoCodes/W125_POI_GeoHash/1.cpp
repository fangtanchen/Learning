#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;

const char base32[40]={
    '0','1','2','3','4','5','6','7','8','9',
    'b','c','d','e','f','g','h','j','k','m',
    'n','p','q','r','s','t','u','v','w','x','y','z'};


int N,M;

void Encode(double longitude,double latitude,char *str){
    double longitude_interval[2]={-180,180};
    double latitude_interval[2]={-90,90};
    int slen=0;
    int len=50;
    int bit=0;
    for(int i=1;i<=len;i++){
        if(i%2){
            double mid=(longitude_interval[0]+longitude_interval[1])/2;
            if(longitude>mid){
                bit=2*bit+1;
                longitude_interval[0]=mid;
            }else{
                 bit*=2;
                 longitude_interval[1]=mid;
            }
        }else{
            double mid=(latitude_interval[0]+latitude_interval[1])/2;
            if(latitude>mid){
                 bit=bit*2+1;
                 latitude_interval[0]=mid;
            }else{
                bit*=2;
                latitude_interval[1]=mid;
            }
        }
        if(i%5==0){
             str[slen++]=base32[bit];
             bit=0;
        }
    }
}

void Decode(char *str,double &latitude,double &longitude){
    int slen=strlen(str);
    double latitude_interval[2]={-90,90};
    double longitude_interval[2]={-180,180};
    bool odd=true;
    for(int si=0;si<slen;si++){
        int pi;
        for(int i=0;i<32;i++){
            if(base32[i]==str[si]){pi=i;break;}
        }
        for(int j=4;j>=0;j--){
            if(odd){
                double mid=(longitude_interval[0]+longitude_interval[1])/2;
                if((1<<j)&(pi)){
                    longitude_interval[0]=mid;
                }else{
                    longitude_interval[1]=mid;
                }
            }else{
                double mid=(latitude_interval[0]+latitude_interval[1])/2;
                if((1<<j)&(pi)){
                    latitude_interval[0]=mid;
                }else{
                    latitude_interval[1]=mid;
                }
            }
            odd=!odd;
        }
    }
    latitude=(latitude_interval[0]+latitude_interval[1])/2;
    longitude=(longitude_interval[0]+longitude_interval[1])/2;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d%d",&N,&M);
    for(int ni=0;ni<N;ni++){
         double longitude,latitude;
         scanf("%lf%lf",&latitude,&longitude);
         char str[20];
         memset(str,0,sizeof(str));
         Encode(longitude,latitude,str);
         printf("%s\n",str);
    }
    for(int mi=0;mi<M;mi++){
         double longitude,latitude;
         char str[20];
         scanf("%s",str);
         Decode(str,latitude,longitude);
         printf("%.6lf %.6lf\n",latitude,longitude);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
