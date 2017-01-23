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
const int MAXN=5e5+5;
typedef long long int ll;

int N;
int C[62][MAXN];
int x[62];


void Swap(int *x,int *y,int num){
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
    memset(C,0,sizeof(C));
    for(int ni=0;ni<N;ni++){
        ll a,b;
        scanf("%lld%lld",&a,&b);
        ll c=a^b;
        s^=a;
        for(int di=0;di<60;di++){
            C[di][ni]=(c>>di)&0x01;
        }
    }
    for(int si=0;si<60;si++){
         C[si][N]=(s>>si)&0x01;
    }
    // important part
    for(int ri=0,ci=0;ri<60&&(ci<N);ci++){
        int mx=ri;
        for(int tmpri=ri;tmpri<60;tmpri++){
            if(C[tmpri][ci]){
                mx=tmpri;break;
            }
        }
        if(!C[mx][ci])continue;
        if(mx!=ri)Swap(C[mx],C[ri],N+1);
        for(int tmpri=ri+1;tmpri<60;tmpri++){
            if(C[tmpri][ci]){
                for(int tmpci=ci;tmpci<=N;tmpci++){
                    C[tmpri][tmpci]^=C[ri][tmpci];
                }
            }
        }
        ri++;
    }
    int t=60;
    for(int ri=0;ri<60;ri++){
        int has=0;
        for(int ci=0;ci<N;ci++){
            has|=C[ri][ci];
        }
        if(0==has){
            if(C[ri][N]){
                return 0*printf("1/1\n");
            }
            t--;
        }
    }
    printf("%lld/%lld\n",((1LL)<<t)-1,(1LL)<<t);




	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
