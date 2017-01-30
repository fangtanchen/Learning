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
const int MAXN=2e5+10;

int a[MAXN],f[MAXN],v[MAXN];
int N,T;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
        scanf("%d",&N);
        for(int i=1;i<=N;i++){
             scanf("%d",a+i);
             a[i+N]=a[i];
        }
        int imax=N<<1;
        for(int i=1;i<=imax;i++){
             int now=i-1;
             for(;now&&a[now]<=a[i];now=f[now])
                 ;
             f[i]=now;
        }
        for(int i=imax;i>=1;i--){
             int now=i+1;
             for(;now<=imax&&a[now]<=a[i];now=v[now])
                 ;
             v[i]=now;
        }
        for(int i=1;i<=N;i++){
            if(f[i+N]==0)printf("-1");
            else{
                if(f[i+N]<=N)printf("%d",f[i+N]);
                else printf("%d",f[i+N]-N);
            }
            printf(" ");
            if(v[i]==N+N+1)printf("-1");
            else{
                if(v[i]<=N)printf("%d",v[i]);
                else printf("%d",v[i]-N);
            }
            printf("\n");

        }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
