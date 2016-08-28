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
const int MAXN=1e5+20;
int num[MAXN];
int map[2][MAXN];
int ans[MAXN];
int cases,N;

void Init(int n){
    memset(num,0,sizeof(num));
    memset(map,0,sizeof(map));
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
        bool flag[2]={true,true};
        for(int ki=0;ki<2;ki++){
             map[ki][1]=ki;
             for(int i=1;i<N;i++){
                 map[ki][i+1]=num[i]-map[ki][i]-map[ki][i-1];
                 if(map[ki][i+1]>1||map[ki][i+1]<0){
                     flag[ki]=false;
                     break;
                 }
             }
             if(map[ki][N-1]+map[ki][N]+map[ki][N+1]!=num[N]){
                 flag[ki]=false;
             }
        }
        int total[2]={0,0};
        memset(ans,-1,sizeof(ans));
        if(flag[0]){
            if(flag[1]) {
                for(int i=1;i<=N;i++){
                    if(map[0][i]==map[1][i]){
                        total[map[0][i]]++;
                        ans[i]=map[0][i];
                    }
                }
            }else{
                for(int i=1;i<=N;i++){
                    total[map[0][i]]++;
                    ans[i]=map[0][i];
                }
            }
        }else if(flag[1]){
            for(int i=1;i<=N;i++){
                 total[map[1][i]]++;
                 ans[i]=map[1][i];
            }
        }
        cout<<total[1];
        for(int i=1;i<=N;i++){
            if(ans[i]==1){
                cout<<" "<<i;
            }
        }
        cout<<endl;
        cout<<total[0];
        for(int i=1;i<=N;i++){
            if(0==ans[i]){
                cout<<" "<<i;
            }
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
