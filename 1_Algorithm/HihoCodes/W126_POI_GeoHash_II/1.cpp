#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef pair<int,int> pii;

const int MAXN=5e4+10;
const int MAXM=110;
const char base32[40]="0123456789bcdefghjkmnpqrstuvwxyz";
map<char,int> mp;

struct Node{
    int nodes[32];//-1：no ways, otherwise:
    int bleaf; //-1: not leaf,  1,2... :leaf,point to point set bleaf
    Node(){
        mem(nodes,-1);
        bleaf=-1;
    }
};


int N,M;
Node trees[MAXN];
int tree_len;
int root;
vector<vii>

void Init(){
    root=0;
    tree_len=1;
    for(int i=0;i<32;i++){
        mp[base32[i]]=i;
    }
}

void Encode(double lon,double lat,int prec,char *ret){
    double lon_int[2]={-180,180};
    double lat_int[2]={-90,90};
    int bits=0;
    int len=5*prec;
    int reti=0;
    for(int i=1;i<=len;i++){
        if(i%2){
            double mid=(lon_int[0]+lon_int[1])/2;
            if(lon<mid){
                 lon_int[1]=mid;
                 bits*=2;
            }else{
                lon_int[0]=mid;
                bits=2*bits+1;
            }
        }else{
             double mid=(lat_int[0]+lat_int[1])/2;
             if(lat<mid){
                 lat_int[1]=mid;
                 bits*=2;
             }else{
                  lat_int[0]=mid;
                  bits=2*bits+1;
             }
        }
        if(i%5==0){
            ret[reti++]=base32[bits];
             bits=0;
        }
    }
    ret[reti++]=0;
}

void Decode(char *str,double &x,double &y){
    double lon_int[2]={-180,180};
    double lat_int[2]={-90,90};
    bool blon=true;
    for(int i=0;str[i];i++){
        int bits=mp[str[i]];
        for(int j=4;j>=0;j--){
            if(blon){
                double mid=(lon_int[0]+lon_int[1])/2;
                if(bits&(1<<j)){
                    lon_int[0]=mid;
                }else{
                    lon_int[1]=mid;
                }
            }else{
                double mid=(lat_int[0]+lat_int[1])/2;
                if(bits&(1<<j)){
                    lat_int[0]=mid;
                }else{
                    lat_int[1]=mid;
                }
            }
            blon=!blon;
        }
    }
    x=(lat_int[0]+lat_int[1])/2;
    y=(lon_int[0]+lon_int[1])/2;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
