#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
const int MAXN=1e9+20;
const int MAXT=1e4+10;
const int MAXS=60;

int anslen=0;
int T,N;
char ans[10000];


bool DFS(int a,int b,int x,int y,int slen){
    if(slen>60)return false;
    if((1==x)&&(1==y)){
        ans[slen]='0';
        ans[slen+1]=0;
        anslen=slen+1;
        return true;
    }
    if(x==y)return false;
    if(x>y){
        int p=(x-1)/y;
        if(slen+p>MAXS)return false;
        for(int si=0;si<p;si++,slen++){
             ans[slen]='1';
        }
        return DFS(a,a*p+b,x-p*y,y,slen);
    }else{
        int p=(y-1)/x;
        if(slen+p>MAXS)return false;
        for(int si=0;si<p;si++,slen++){
             ans[slen]='0';
        }
        return DFS(a+p*b,b,x,y-p*x,slen);
    }
}

int Gcd(int x,int y){
    if(x%y==0)return y;
    return Gcd(y,x%y);
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
        int ni;
        do{
            anslen=0;
            memset(ans,0,sizeof(ans));
            ni=rand()%N+2;
            if(ni>=N||Gcd(ni,N)!=1)continue;
            if(!DFS(0,1,ni,N,0))continue;
            if(anslen<=60){
                //printf("\n\n%d  %d\n",anslen,strlen(ans));
                printf("%s\n",ans);
                break;
            }
        }while(1);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
