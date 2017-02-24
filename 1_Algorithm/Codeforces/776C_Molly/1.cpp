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
typedef long long int LL;
const int MAXN=1005;

map<LL,int> mp;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int n,k;
    scanf("%d%d",&n,&k);
    mp[0]=1;
    LL sum=0;
    LL ans=0;
    for(int i=0;i<n;i++){
        LL x;
        scanf("%lld",&x);
        sum+=x;
        if(k==1){
             ans+=mp[sum-1];
        }else if(-1==k){
            ans+=mp[sum-1];
            ans+=mp[sum+1];
        }else{
            LL b=1;
            while(b<1e15){
                ans+=mp[sum-b];
                b*=k;
            }
        }
        mp[sum]++;
    }
    printf("%lld\n",ans);


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
