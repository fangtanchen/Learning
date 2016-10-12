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
#define MAXN 20005
#define MAXM 100005
int f[MAXM];
int sumb[MAXM];
int sums[MAXM];
int N,T;
int tree[MAXM];

int lowbit(int k){
     return k&-k;
}

void init(){
    memset(tree,0,sizeof(tree));
}

int add(int k,int a){
    while(k<=MAXM){
         tree[k]+=a;
         k+=lowbit(k);
    }
    return 0;
}

int query(int k){
     int res=0;
     while(k>0){
         res+=tree[k];
         k-=lowbit(k);
     }
     return res;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        init();
        for(int ni=0;ni<N;ni++){
            scanf("%d",ni+f);
            int temp=query(f[ni]);
            sums[f[ni]]=temp;
            sumb[f[ni]]=ni-temp;
            add(f[ni],1);
        }
        long long int ans=0;
        for(int ni=1;ni<N;ni++){
             int temps=query(f[ni])-1;
             int tempb=N-temps-1;
             ans=ans+(sums[f[ni]]*(tempb-sumb[f[ni]]))
                 +(sumb[f[ni]]*(temps-sums[f[ni]]));
        }
        printf("%lld\n",ans);
    }


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
