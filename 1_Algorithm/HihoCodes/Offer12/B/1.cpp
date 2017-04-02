#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;
map<int,int> mp;
int K[MAXN];
int N,C;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int ni=0;ni<N;ni++){
         cin>>C;
         int sum=0;
         int x;
         for(int j=0;j<C;j++){
             cin>>x;
             sum+=x;
             if(mp.find(sum)==mp.end()){
                  mp[sum]=0;
             }
             mp[sum]++;
         }
         mp[sum]=0;
    }
    int t=0;
    for(map<int,int>::iterator it=mp.begin();
            it!=mp.end();it++){
         t=max(t,it->second);
    }
    cout<<N-t<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
