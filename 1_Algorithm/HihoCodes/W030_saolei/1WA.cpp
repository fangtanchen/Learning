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
const int MAXN=1e5+10;
int known[MAXN];
int map[MAXN];
int num[MAXN];
int cases,N;


void Init(int N){
     memset(known,0,sizeof(known));
     known[0]=known[N+1]=1;
     memset(map,0,sizeof(map));
     map[0]=map[N+1]=1;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>cases;
    while(cases--){
         cin>>N;
         Init(N);
         for(int ni=1;ni<=N;ni++){
              cin>>num[ni];
         }
         for(int i=3;i<=N;i+=3){
             known[i]=1;
             map[i]=num[i-1]-num[i-2]+map[i-3];
         }
         if(N%3!=2){
             for(int i=N-2;i>=1;i-=3){
                 known[i]=1;
                 map[i]=num[i+1]-num[i+2]+map[i+3;]
             }
             for(int i=1;i<=N;i++){
                  if(known[i]==1)continue;
                  map[i]=num[i]-map[i-1]-map[i+1];
             }
         }else{
            int tpi=-1;
            int tmpcnt=known[0]+known[1];
            int ti=0;
            do{
                ti++;
                tmpcnt=tmpcnt+known[ti+1];
                if(3==tmpcnt){
                     tpi=ti;
                     break;
                }
                tmpcnt=tmpcnt-known[ti-1];
            }while(ti<=N;)
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
