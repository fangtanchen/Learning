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
const int MODN=1e9+7;

int n;
int d[MAXN],num[MAXN];
int dp[MAXN];



int lowbit(int k){
    return k&-k;
}


void Add(int k,int val){
    while(k<=n){
        dp[k]+=val;
        dp[k]%=MODN;
        k+=lowbit(k);
    }
}

int GetSum(int k){
    int sum=0;
    while(k>=1){
        sum=(sum+dp[k])%MODN;
        k-=lowbit(k);
    }
    return sum;
}

int Find(int k){
    int l=1,r=n+1;
    while(l<r){
        int mid=(l+r)/2;
        if((d[mid]==k)&&(d[mid-1]<k))return mid;
        if(d[mid]<k)l=mid+1;
        else r=mid;
    }
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    while(cin>>n){
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            cin>>num[i];
            d[i]=num[i];
        }
        sort(d+1,d+n+1);
        for(int i=1;i<=n;i++){
            int id=Find(num[i]);
            Add(id,GetSum(id)+1);
        }
        cout<<GetSum(n)<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
