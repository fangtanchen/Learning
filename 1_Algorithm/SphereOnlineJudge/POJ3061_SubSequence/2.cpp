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

int N,S;
int A[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    cin>>T;
    while(T--){
        cin>>N>>S;
        for(int i=0;i<N;i++)cin>>A[i];
        int l=0,r=0,sum=0;
        int ans=N+1;
        while(1){
            while(r<N &&sum<S){
                sum+=A[r];
                r++;
            }
            if(sum<S)break;
            ans=min(ans,r-l);
            sum-=A[l];
            l++;
        }
        if(ans==N+1)ans=0;
        cout<<ans<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
