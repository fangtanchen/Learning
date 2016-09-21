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
const int MAXN=1e6+20;

int num[MAXN];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int N,K;
    cin.sync_with_stdio(false);
    cin>>N>>K;
    for(int i=0;i<N;i++){
         cin>>num[i];
    }
    int cnt=1;
    bool flag=false;
    for(int i=0;i<N;i++){
        if(num[i]<K){
             cnt++;
        }
        if(K==num[i])flag=true;
    }
    if(flag)cout<<cnt<<endl;
    else cout<<-1<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
