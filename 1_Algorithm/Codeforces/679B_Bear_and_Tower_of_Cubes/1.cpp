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
typedef long long LL;
typedef pair<LL,LL> pll;
map<LL ,pll> mp;

LL M;

void dfs(LL x){
    if(mp.find(x)!=mp.end())return ;
    LL l=0,r=1e5+10;
    while(l+1<r){
         LL mid=(l+r)/2;
         if(mid*mid*mid<=x){
             l=mid;
         }else{
             r=mid;
         }
    }
    LL k=l*l*l;
    dfs(k-1);
    dfs(x%k);
    LL t1=mp[k-1].first+x/k-1;
    LL t2=mp[x%k].first+x/k;
    if(t1>t2){
        mp[x]=make_pair(t1,mp[k-1].second+(x/k-1)*k);
    }else{
        mp[x]=make_pair(t2,mp[x%k].second+x/k*k);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>M;
    mp[0]=make_pair(0,0);
    mp[1]=make_pair(1,1);
    mp[2]=make_pair(2,2);
    dfs(M);
    cout<<mp[M].first<<" "<<mp[M].second<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
