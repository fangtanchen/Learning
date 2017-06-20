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
const int MAXN=1e5+10;
typedef long long int LL;

LL T,N;
LL A[MAXN];

LL Gcd(LL x,LL y){
    if(y==0)return x;
    else return Gcd(y,x%y);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin.sync_with_stdio(false);
    cin>>T;
    while(T--){
        cin>>N;
        for(int i=1;i<=N;i++){
            cin>>A[i];
        }
        if(N==1){
            cout<<A[1]<<"/"<<1<<endl;
            continue;
        }
        LL x=0;
        LL y=N*(N-1)/2;
        LL t=0;
        LL cnt[64];
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=N;i++){
            for(int k=0;k<=33;k++){
                if((A[i]&(1LL<<k))){
                    x=x+(i-1)*(1LL<<k);
                    cnt[k]++;
                }else{
                    x=x+(cnt[k])*(1LL<<k);
                }
            }
            t=t+x/y;
            x=x%y;
        }
        LL d=Gcd(x,y);
        x/=d;
        y/=d;

        x=t*y+x;

        d=Gcd(x,y);
        x/=d;
        y/=d;
        cout<<x<<"/"<<y<<endl;
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
