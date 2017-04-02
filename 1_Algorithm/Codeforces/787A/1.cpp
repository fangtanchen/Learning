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
const int MAXN=1005;

int a,b,c,d;


int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

void exgcd(int A,int B,int &x,int &y){
    if(B==0){
        x=1;
        y=0;
        return;
    }
    int tx,ty;
     exgcd(B,A%B,tx,ty);
     x=ty;
     y=(tx-A/B*ty);
}

int Solve(int A,int B,int C){
    int g=gcd(A,B);
    if(0==C){
        return 0;
    }
    if(C%g!=0)return -1;
    A/=g;B/=g;C/=g;
    int x,y;
    exgcd(A,B,x,y);
    x=x*C%B;
    if(x<0)x+=B;
    return x;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>a>>b>>c>>d;
    int ans=Solve(a,c,d-b);
    if(ans!=-1)ans=a*ans+b;
    printf("%d\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
