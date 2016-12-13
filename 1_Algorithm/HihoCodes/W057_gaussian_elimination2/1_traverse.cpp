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
const int MAXR=5;
const int MAXC=6;
const int dir[5][2]={-1,0,0,-1,0,0,0,1,1,0};

int map[MAXR+10][MAXC+10];
int st[MAXR+10];
char str[MAXC+10];

int xri[1000],xci[1000],xlen;

int str2int(int *s,int &ret){
    ret=0;
    for(int i=1;i<=MAXC;i++){
        ret=ret*2+s[i];
    }
    return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    for(int ri=1;ri<=MAXR;ri++){
        for(int ci=1;ci<=MAXC;ci++){
            scanf("%1d",map[ri]+ci);
        }
        str2int(map[ri],st[ri]);
    }
    xlen=0;
    for(int pi=0;pi<64;pi++){
         st[0]=pi;
         for(int ri=0;ri<=MAXR;ri++){
             int tmp=st[ri];
             for(int ci=MAXC;ci>=1;ci--){
                 map[ri][ci]=tmp%2;
                 tmp/=2;
             }
         }
         xlen=0;
         for(int ri=1;ri<=MAXR;ri++){
             for(int ci=1;ci<=MAXC;ci++){
                 if(map[ri-1][ci]==0){
                      xri[xlen]=ri;
                      xci[xlen++]=ci;
                      for(int di=0;di<5;di++){
                          int tmpri=ri+dir[di][0];
                          int tmpci=ci+dir[di][1];
                          map[tmpri][tmpci]=1-map[tmpri][tmpci];
                      }
                 }
             }
         }
         bool flag=true;
         for(int ci=1;ci<=MAXC;ci++){
             if(map[MAXR][ci]==0){
                 flag=false;
             }
         }
         if(flag)break;
    }
    printf("%d\n",xlen);
    for(int i=0;i<xlen;i++){
        printf("%d %d\n",xri[i],xci[i]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
