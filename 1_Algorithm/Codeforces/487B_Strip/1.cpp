#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;

multiset<int> st,ret;
int n,s,l;
int a[MAXN],dp[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>n>>s>>l;
    for(int i=1;i<=n;i++){
         cin>>a[i];
    }
    for(int i=1,j=1;i<=n;i++){
        st.insert(a[i]);
        for(;*st.rbegin()-*st.begin()>s;j++){
            st.erase(st.find(a[j]));
            if(i-j>=l){
                ret.erase(ret.find(dp[j-1]));
            }
        }
        if(i-j+1>=l){
             ret.insert(dp[i-l]);
        }
        if(ret.size()==0)dp[i]=MAXN;
        else dp[i]=*ret.begin()+1;
    }
    printf("%d\n",(dp[n]>=MAXN?-1:dp[n]));

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
