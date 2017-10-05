#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<bitset>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e5+10;

bitset<MAXN> a,b,c,p[MAXN];
int N,M;
int A[MAXN],id[MAXN];
int l[3],r[3];

bool Cmp(int x,int y){
    return A[x]<A[y];
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>M;
    for(int ni=1;ni<=N;ni++){
         cin>>A[ni];
         id[ni]=ni;
    }
    sort(id+1,id+N+1,Cmp);
    /*
    for(int i=1;i<=N;i++){
         cout<<A[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=N;i++){
         cout<<id[i]<<" ";
    }
    cout<<endl;
    */
    for(int i=1;i<=N;i++){

    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
