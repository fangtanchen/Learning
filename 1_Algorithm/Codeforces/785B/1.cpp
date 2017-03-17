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
typedef pair<int,int> pii;
const int MAXN=2e5+10;


pii A[MAXN],B[MAXN],C[MAXN];
int N,M;


bool Cmp2(pii x,pii y){
    if(x.second<y.second)return true;
    else if(x.second==y.second&&x.first<y.first)
        return true;

    return false;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N;
    for(int i=1;i<=N;i++){
         cin>>A[i].first>>A[i].second;
    }
    cin>>M;
    for(int i=1;i<=M;i++){
         cin>>B[i].first>>B[i].second;
         C[i]=B[i];
    }
    sort(A+1,A+1+N);
    sort(B+1,B+1+M);
    sort(C+1,C+1+M,Cmp2);

    int ans=0;
    for(int i=1;i<=N;i++){
        if(C[1].second<A[i].first){
            ans=max(ans,A[i].first-C[1].second);
        }
        if(B[M].first>A[i].second){
             ans=max(ans,B[M].first-A[i].second);
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
