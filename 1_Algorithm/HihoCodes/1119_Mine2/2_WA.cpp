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
const int MAXN=210;
const int MAXM=210;
const int dir[8][2]={{-1,-1},{-1,0},{-1,1},
                     {0,-1},{0,1},
                     {1,-1},{1,0},{1,1}};

int cnt[MAXN][MAXM];
int map[MAXN][MAXM];
int mine[MAXN][MAXM];
int cases,N,M;
int total[2];


void Init(){
     memset(cnt,0,sizeof(cnt));
     memset(map,-1,sizeof(map));
     memset(mine,-1,sizeof(mine));
     total[0]=total[1]=0;
}

bool Check(int ri,int ci){
    return (ri>=1)&&(ri<=N)&&(ci>=1)&&(ci<=M);
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
         for(int ri=1;ri<=N;ri++){
             for(int ci=1;ci<=M;ci++){
                 cin>>map[ri][ci];
                 if(-1!=map[ri][ci]){
                     mine[ri][ci]=0;
                 }
             }
         }
         for(int ri=1;ri<=N;ri++){
             for(int ci=1;ci<=M;ci++){
                 if(-1!=map[ri][ci]){
                     for(int di=0;di<8;di++){
                         int tmpri=ri+dir[di][0];
                         int tmpci=ci+dir[di][1];
                         if(!Check(tmpri,tmpci))continue;
                         if(-1==map[tmpri][tmpci])
                             cnt[ri][ci]++;
                     }
                 }
             }
         }

         for(int ri=1;ri<=N;ri++){
             for(int ci=1;ci<=M;ci++){
                 if(-1==map[ri][ci])continue;
                 //rule 1
                 if(0==map[ri][ci]){
                     for(int di=0;di<8;di++){
                         int tmpri=ri+dir[di][0];
                         int tmpci=ci+dir[di][1];
                         if(!Check(tmpri,tmpci))continue;
                         if(map[tmpri][tmpci]==-1){
                             mine[tmpri][tmpci]=0;
                         }
                     }
                 }
                //rule2
                 else if((map[ri][ci]==cnt[ri][ci])){
                     for(int di=0;di<8;di++){
                         int tmpri=ri+dir[di][0];
                         int tmpci=ci+dir[di][1];
                         if(!Check(tmpri,tmpci))continue;
                         if(-1==map[tmpri][tmpci]){
                             mine[tmpri][tmpci]=1;
                         };
                     }
                 }
                 //rule3
                 for(int di=0;di<8;di++){
                     int nbri=ri+dir[di][0];
                     int nbci=ci+dir[di][1];
                     if(!Check(nbri,nbci))continue;
                     if(-1==map[nbri][nbci])continue;
                     bool flag=true;
                     for(int pi=0;pi<8;pi++){
                          int tmpri=nbri+dir[pi][0];
                          int tmpci=nbci+dir[pi][1];
                          if(!Check(tmpri,tmpci))continue;
                          if(-1==map[tmpri][tmpci]){
                              if(abs(ri-tmpri)>1 ||abs(ci-tmpci)>1){
                                   flag=false;
                                   break;
                              }
                          }
                     }
                     if(flag){
                         if((cnt[ri][ci]-cnt[nbri][nbci])
                                 !=(map[ri][ci]-map[nbri][nbci]))
                             continue;
                         for(int pi=0;pi<8;pi++){
                             int tmpri=ri+dir[pi][0];
                             int tmpci=ci+dir[pi][1];
                             if(!Check(tmpri,tmpci))continue;
                             if(-1==map[tmpri][tmpci]){
                                 if((abs(nbri-tmpri)>1)
                                         ||(abs(nbci-tmpci)>1)){
                                      mine[tmpri][tmpci]=1;
                                 }
                             }
                         }
                     }
                 }
             }
         }
         for(int ri=1;ri<=N;ri++){
             for(int ci=1;ci<=M;ci++){
                 if(map[ri][ci]!=-1)continue;
                 if(mine[ri][ci]==0)total[0]++;
                 else if(mine[ri][ci]==1)total[1]++;
             }
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