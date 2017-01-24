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
typedef long long int ll;

const int MAXN=5e5+5;

int N;
int C[60][MAXN];

void SwapRow(int *x,int *y,int num){
    for(int i=0;i<num;i++){
        swap(x[i],y[i]);
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    ll s=0;
    for(int ni=0;ni<N;ni++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        s^=a;b^=a;
        for(int bi=0;bi<60;bi++){
             C[bi][ni]=((b>>bi)&0x01);
        }
    }
    for(int si=0;si<60;si++){
        C[si][N]=((s>>si)&0x01);
    }
    for(int ri=0,ci=0;ri<60&&ci<N;ci++){
        int mx=ri;
        for(int tmpri=ri;tmpri<60;tmpri++){
            if(C[tmpri][ci]){
                mx=tmpri;
                break;
            }
        }
        if(C[mx][ci]==0)continue;
        if(ri!=mx)SwapRow(C[mx],C[ri],N+1);
        for(int tmpri=ri+1;tmpri<60;tmpri++){
            if(C[tmpri][ci]==0)continue;
            for(int tmpci=ci;tmpci<=N;tmpci++){
                C[tmpri][tmpci]^=C[ri][tmpci];
            }
        }
        ri++;
    }
    int ans=60;
    for(int ri=0;ri<60;ri++){
        int has=0;
        for(int ci=0;ci<N;ci++){
            has+=C[ri][ci];
        }
        if(0==has){
            if(C[ri][N]){
                return 0*printf("1/1\n");
            }
            ans--;
        }
    }
    printf("%lld/%lld\n",(1LL<<ans)-1,(1LL<<ans));

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
