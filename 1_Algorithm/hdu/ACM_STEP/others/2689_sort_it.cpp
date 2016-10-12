#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAXN 1010

int tree[MAXN];

int lowbit(int k){
    return k&-k;
}
int add(int k,int a){
    while(k<MAXN){
         tree[k]+=a;
         k+=lowbit(k);
    }
    return 0;
}

int query(int end){
     int sum=0;
     while(end>0){
         sum+=tree[end];
         end-=lowbit(end);
     }
     return sum;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n;
    while(EOF!=scanf("%d",&n)){
         int s;
         int res=0;
         memset(tree,0,sizeof(tree));
         for(int i=0;i<n;i++){
             scanf("%d",&s);
             add(s+1,1);
             res+=i-query(s);
         }
         printf("%d\n",res);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
