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
const int MAXN=310;

int map[MAXN][MAXN];
int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            cin>>map[i][j];
        }
    }

    int ans=N*(N-1)/2;
    for(int i=1;i<N;i++){
        for(int j=i+1;j<=N;j++){
            bool flag=false;
            for(int k=1;k<=N;k++){
                if(flag)break;
                if(k==i||k==j)continue;
                if(map[i][j]==map[i][k]+map[k][j]) {
                    ans--;
                    flag=true;
                }
            }
        }
    }
    cout<<ans<<endl;
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
