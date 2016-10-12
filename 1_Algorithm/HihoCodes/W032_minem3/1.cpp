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
const int MAXN=15;
int G[MAXN][MAXN];//-2 means yes, -3 means no
int remain[MAXN][MAXN];
int f[MAXN];
int slen;
int s[MAXN][2];
int cases,N,M;
const int dir[8][2]={{-1,-1},{-1,0},{-1,1},
                    {0,-1},{0,1},
                    {1,-1},{1,0},{1,1}};

void Init(){
    memset(f,0,sizeof(f));
    slen=0;
}

bool InMap(int ri,int ci){
    return (ri>=1)&&(ri<=N)&&(ci>=1)&&(ci<=M);
}

bool Check(int ri,int ci){
    // check if there is 0 around (ri,ci)
    // true: no zero around, false: zero around
    for(int i=0;i<8;i++){
        int tmpri=ri+dir[i][0];
        int tmpci=ci+dir[i][1];
        if(!InMap(tmpri,tmpci))continue;
        if(0==remain[tmpri][tmpci]){
            return false;
        }
    }
    return true;
}

void Work(int k){
    if(k<slen){
        int ri=s[k][0];
        int ci=s[k][1];
        if(Check(ri,ci)){
             G[ri][ci]=-2;
             for(int di=0;di<8;di++){
                 int tmpri=ri+dir[di][0];
                 int tmpci=ci+dir[di][1];
                 if(!InMap(tmpri,tmpci))continue;
                 if(remain[tmpri][tmpci]>0)
                    remain[tmpri][tmpci]--;
             }
             Work(k+1);
             for(int di=0;di<8;di++){
                 int tmpri=ri+dir[di][0];
                 int tmpci=ci+dir[di][1];
                 if(!InMap(tmpri,tmpci))continue;
                 if(remain[tmpri][tmpci]>=0)
                     remain[tmpri][tmpci]++;
             }
        }
        G[ri][ci]=-3;
        Work(k+1);
    }else{
        for(int si=0;si<slen;si++){
            int ri=s[si][0];
            int ci=s[si][1];
            for(int di=0;di<8;di++){
                int tmpri=ri+dir[di][0];
                int tmpci=ci+dir[di][1];
                if(!InMap(tmpri,tmpci))continue;
                if(remain[tmpri][tmpci]>0){
                    return ;
                }
            }
        }
        for(int si=0;si<slen;si++){
            int ri=s[si][0],ci=s[si][1];
            if(f[si]==0){
                f[si]=G[ri][ci];
            }else{
                if(f[si]!=G[ri][ci]){
                    f[si]=-1;
                }
            }
        }
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>cases;
    while(cases--){
         cin>>N>>M;
         Init();
         for(int i=1;i<=N;i++){
             for(int j=1;j<=M;j++){
                 cin>>G[i][j];
                 remain[i][j]=G[i][j];
                 if(-1==G[i][j]){
                     s[slen][0]=i;
                     s[slen][1]=j;
                     slen++;
                 }
             }
         }
         Work(0);
         int total[2]={0,0};
         for(int si=0;si<slen;si++){
              if(f[si]==-2)total[1]++;
              if(f[si]==-3)total[0]++;
         }
         cout<<total[1]<<" "<<total[0]<<endl;

    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
