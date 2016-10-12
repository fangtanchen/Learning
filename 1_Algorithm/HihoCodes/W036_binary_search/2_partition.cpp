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
const int MAXN=1e6+10;

int num[MAXN];
int N,K;

int Partition(int begin,int end,int val){
    if(begin==end){
        return num[begin]<=val;
    }else{
        int mid=(begin+end)/2;
        return Partition(begin,mid,val)
            +Partition(mid+1,end,val);
    }
    return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>K;
    bool flag=false;
    for(int i=1;i<=N;i++){
         cin>>num[i];
         if(K==num[i])flag=true;
    }
    if(!flag)cout<<-1<<endl;
    else cout<<Partition(1,N,K)<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
