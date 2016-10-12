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
const int INF=0x7f7f7f7f;

int a[MAXN];

int N,K;

int Partition(int begin,int end,int k){
    while(begin<=end){
        int mid=(begin+end)/2;
        int amid=a[mid];
        int i=begin;
        int j=end;
        while(1){
            for(;a[i]<amid;i++)
                ;
            for(;a[j]>amid;j--)
                ;
            if(i>=j)break;
            swap(a[i],a[j]);
        }
        int pos=i-begin+1;
        if(pos==k){
            return amid;
        }else if(pos<k){
            k=k-pos;
            begin=i+1;
        }else{
            end=i-1;
        }

    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>N>>K;
    for(int i=1;i<=N;i++){
         cin>>a[i];
    }
    a[0]=INF;
    a[N+1]=-1;
    if(K>N||K<1)cout<<-1<<endl;
    else cout<<Partition(1,N,K)<<endl;


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
