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
typedef long long LL;
const int MAXN=1e5+10;

LL A[MAXN],B[MAXN];
int N;
LL ans;

void DFS(int l,int r){
    if(l==r)return ;
    int mid=(l+r)/2;
    DFS(l,mid);
    DFS(mid+1,r);
    int i=l,j=mid+1;
    int pt=l;
    while((i<=mid)&&(j<=r)){
        if(A[i]<=A[j]){
            B[pt++]=A[i++];
        }else{
            B[pt++]=A[j++];
            ans+=(mid-i+1);
        }
    }
    while(i<=mid){
         B[pt++]=A[i++];
    }
    while(j<=r){
        B[pt++]=A[j++];
    }
    for(int k=l;k<=r;k++){
         A[k]=B[k];
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++){
         cin>>A[i];
    }
    ans=0;

    DFS(1,N);
    cout<<ans<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
