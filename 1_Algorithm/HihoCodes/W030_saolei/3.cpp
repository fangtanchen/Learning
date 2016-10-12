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
int map[2][MAXN];
int num[MAXN];
int ans[MAXN];
int flag[2];
int cases,N;

void Init(int n){
    memset(map,0,sizeof(map));
    memset(ans,-1,sizeof(ans));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>cases;
    while(cases--){
         cin>>N;
         Init(N);
         for(int i=1;i<=N;i++){
             cin>>num[i];
         }
         for(int ki=0;ki<2;ki++){
            map[ki][1]=ki;
            flag[ki]=1;
            for(int i=1;i<=N;i++){
                map[ki][i+1]=num[i]-map[ki][i]-map[ki][i-1];
                if(map[ki][i+1]>1||map[ki][i+1]<0){
                    flag[ki]=0;
                    break;
                }
            }
            if(map[ki][N+1]!=0){
                 flag[ki]=0;
            }
         }
         int total[2]={0,0};
         if(flag[0]&&flag[1]){
             for(int i=1;i<=N;i++){
                 if(map[0][i]==map[1][i]){
                      ans[i]=map[0][i];
                      total[map[0][i]]++;
                 }
             }
         }else{
             if(flag[0]){
                 for(int i=1;i<=N;i++){
                     ans[i]=map[0][i];
                     total[map[0][i]]++;
                 }
             }
             else if(flag[1]){
                 for(int i=1;i<=N;i++){
                     ans[i]=map[1][i];
                     total[map[1][i]]++;
                 }
             }
         }
         cout<<total[1];
         for(int i=1;i<=N;i++){
              if(1==ans[i])cout<<" "<<i;
         }
         cout<<endl;
         cout<<total[0];
         for(int i=1;i<=N;i++){
              if(0==ans[i])cout<<" "<<i;
         }
         cout<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
