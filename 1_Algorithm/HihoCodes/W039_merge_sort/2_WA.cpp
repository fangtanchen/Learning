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

int A[MAXN],B[MAXN];
int N;
int ans;

void DFS(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    DFS(1,mid);
    DFS(mid+1,r);
    int i=l,j=mid+1;
    int pt=l;
    while((j<=r)&&(i<=mid)){
        if(A[j]>A[i]){
            B[pt]=A[i];
            pt++;i++;
        }else{
            B[pt]=A[j];
            pt++;j++;
        }
    }
    while(j<=r){
        B[pt++]=A[j++];
    }
    while(i<=mid){
        B[pt++]=A[i++];
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
    cout<<(N*(N-1))/2-ans<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
