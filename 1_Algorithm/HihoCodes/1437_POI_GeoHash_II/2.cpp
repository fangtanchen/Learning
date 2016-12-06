#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
#include<set>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define mem(a,b) memset(a,b,sizeof(a))
typedef pair<double ,double > pdd;

const int MAXN=1e6+10;
const int MAXM=110;
const double RADIUS=6e6;
const char base32[40]="0123456789bcdefghjkmnpqrstuvwxyz";
const double PI=acos(-1.0);
const int dir[9][2]={{-1,-1},{-1,0},{-1,1},
    {0,-1},{0,0},{0,1},
    {1,-1},{1,0},{1,1}};

#define Angle2Rad(x) (x/180.0*PI)
#define Rad2Angle(x) (x/PI*180.0)

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
vector<pdd> G[MAXN];
int Glen;
double  dlat,dlon;

void Init(){
    root=0;
    tree_len=1;
    Glen=0;
    for(int i=0;i<32;i++){
        mp[base32[i]]=i;
    }
    dlat=180.0/(1<<15);//fd
    dlon=360.0/(1<<15);//fdfd
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


void TrieInsert(int rt,double lat,double lon,char *str){
    if(str[0]==0){
        if(trees[rt].bleaf==-1){
            trees[rt].bleaf=Glen++;
        }
        G[trees[rt].bleaf].push_back(pdd(lat,lon));
        return;
    }else{
        int noi=mp[str[0]];
        if(-1==trees[rt].nodes[noi]){
            trees[rt].nodes[noi]=tree_len++;
        }
        TrieInsert(trees[rt].nodes[noi],lat,lon,str+1);
    }
}

void TrieQuery(int rt,char *query,int &id){
    if(query[0]==0){
        id=rt;
        return;
    }
    int noi=mp[query[0]];
    if(trees[rt].nodes[noi]==-1){
        return;
    }
    TrieQuery(trees[rt].nodes[noi],query+1,id);
}

void Polar2Cart(double radius,double lat,double lon,double &x,double &y,double &z){
    x=radius*cos(lat)*cos(lon);
    y=radius*cos(lat)*sin(lon);
    z=radius*sin(lat);
}

void Cart2Polar(double x,double y,double z,double radius,double &lat,double &lon){
    lat=asin(z/radius);
    lon=asin(y/radius/cos(lat));
}

double SurDist(pdd A,pdd B){
//    return RADIUS*acos(cos(A.first)*cos(B.first)*cos(A.second-B.second)
//            +sin(A.first)*sin(B.first));
    return RADIUS*acos(cos(A.first-B.first)*cos(A.second-B.second));
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    Init();
    scanf("%d%d",&N,&M);

    for(int ni=0;ni<N;ni++){
        double lat,lon;
        scanf("%lf%lf",&lat,&lon);
//        lat=Angle2Rad(lat);lon=Angle2Rad(lon);
        char ret[20];
        Encode(lat,lon,6,ret);
        TrieInsert(root,Angle2Rad(lat),Angle2Rad(lon),ret);
    }

    for(int mi=0;mi<M;mi++){
        double lat,lon;
        int ans=0;
        scanf("%lf%lf",&lat,&lon);
        set<int> s;
        s.clear();
        double plat=Angle2Rad(lat),plon=Angle2Rad(lon);
        for(int di=0;di<9;di++){
            double tmplat=lat+dir[di][0]*dlat;
            double tmplon=lon+dir[di][1]*dlon;
            char ret[20];
            int id=-1;
            Encode((tmplat),(tmplon),6,ret);
            TrieQuery(root,ret,id);
            if(id==-1)continue;
            if(s.count(id)>0)continue;
            s.insert(id);
            int tt=trees[id].bleaf;
            for(int ki=G[tt].size()-1;
                    ki>=0;ki--){
                 ans+=(SurDist(pdd(plat,plon),G[tt][ki])<=500);
            }
        }
        printf("%d\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
