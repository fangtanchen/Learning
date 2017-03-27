#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1005;
const int MAXM=6;
const int MAXS=1025;
const int MOD=1e9+7;

int dp[MAXN][MAXM][MAXS];



int main(){
	#ifdef L_JUDGE
		freopen("dict.txt","r",stdin);
		freopen("in.txt","w",stdout);
	#endif
    vector<string> dict;
    int x;
    string str;
    srand(time(NULL));
    for(int i=0;i<1000;i++){
        cin>>x>>str;
        dict.push_back(str);
    }
    for(int i=1;i<=1000000;i++){
        int id=rand()%1000;
        cout<<dict[id];
    }
    printf("\n1000\n");
    for(int i=0;i<1000;i++){
         cout<<dict[i]<<endl;
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
