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


class Stones {
    public:

        vector<int> result(int A, int B, int n, vector<int> e, vector<int> a) {
            // write code here
            long long int sum[110];
            sum[e.size()]=0;
            for(int i=e.size()-1;i>=0;i--){
                sum[i]+=sum[i+1]+a[i];
            }
            // ith stone
            // energy: 0: lower or equal, 1:higher
            // first,second
            long long int dp[110][2];
            memset(dp,0,sizeof(dp));
            for(int i=e.size()-1;i>=0;i--){
                dp[i][1]
            }
        }

};


int main(){
#ifdef L_JUDGE
    freopen("in.txt","r",stdin);
    //		freopen("out.txt","w",stdout);
#endif
    vector<int> e,a;
    int kk[]={66,2,6,2,8,4,3};
    int tt[]={7,12,65,7,4,40,15};
    for(int i=0;i<7;i++)
        e.push_back(kk[i]),a.push_back(tt[i]);
    Stones st;
    st.result(9,0,7,e,a);


#ifdef L_JUDGE
    fclose(stdin);
    fclose(stdout);
    //		system("out.txt");
#endif

    return 0;
}
