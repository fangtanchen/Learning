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

int Partition(int begin,int end,int k){
    while(begin<=end){
        int i=begin;
        int j=end;
        int mid=(i+j)/2;
        int amid=num[mid];
        while(1){
            for(;num[i]<amid;i++)
                ;
            for(;num[j]>amid;j--)
                ;
            if(i==j)break;
            swap(num[i],num[j]);
        }
        int pos=i-begin+1;
        if(k==pos){
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
    scanf("%d%d",&N,&K);
    for(int i=0;i<N;i++){
         scanf("%d",num+i);
    }
    if(K>=N||K<0)printf("-1\n");
    else{
        printf("%d\n",Partition(0,N-1,K));
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
