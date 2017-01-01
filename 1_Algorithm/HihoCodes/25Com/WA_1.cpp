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
const int MAXN=1e9+20;
const int MAXT=1e4+10;
const int MAXS=100;

char ans[1000000];
int anslen=0;
int T,N;

bool Solve(int a,int b,int x,int y,int slen){
    if((1==x)&&(1==y)){
        ans[slen]='0';
        ans[slen+1]=0;
        return true;
    }
    if(x==y)return false;
    if(x>y){
        int p=(x-1)/y;
        for(int si=0;si<p;si++,slen++){
            ans[slen]='1';
        }
        return Solve(a,a*p+b,x-p*y,y,slen);
    }else{
         int p=(y-1)/x;
        for(int si=0;si<p;si++,slen++){
            ans[slen]='0';
        }
        return Solve(a+p*b,b,x,y-p*x,slen);
    }
}

bool DFS(int a,int b,int x,int y,int slen){
    if((1==x)&&(1==y)){
        ans[slen]='0';
        ans[slen+1]=0;
        return true;
    }
    if(x==y)return false;
    if(x>y){
        int p=(x-1)/y;
        return DFS(a,a*p+b,x-p*y,y,slen);
    }else{
         int p=(y-1)/x;
        return DFS(a+p*b,b,x,y-p*x,slen);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&T);
    while(T--){
         scanf("%d",&N);
         memset(ans,0,sizeof(ans));
         int l=1,r=N;
         while(l<=r){
             anslen=0;
             int mid=(l+r)/2;
             if(DFS(0,1,mid,N,anslen)){
                 l=mid+1;
             }else{
                 r=mid-1;
             }
         }
         memset(ans,0,sizeof(ans));
         Solve(0,1,r,N,0);
         printf("\n\n%d\n",strlen(ans));
         printf("%s\n",ans);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
