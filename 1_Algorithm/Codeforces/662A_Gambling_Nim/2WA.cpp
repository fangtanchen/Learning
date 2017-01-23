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
        for(int di=0;di<60&&c;di++){
            C[di][ni]=c&0x01;
            c>>=1;
        }
    }
    for(int si=0;si<60&&s;si++){
         C[si][N]=s&0x01;
         s>>=1;
    }
    int imax=min(60,N);
    for(int ri=0;ri<imax;ri++){
        bool flag=false;
        for(int tmpri=ri;tmpri<60;tmpri++){
            if(C[tmpri][ri]){
                if(tmpri!=ri)Swap(C[tmpri],C[ri],1+N);
                flag=true;
                break;
            }
        }
        if(!flag)continue;
        for(int tmpri=ri+1;tmpri<60;tmpri++){
            if(C[tmpri][ri]){
                for(int j=ri;j<=N;j++){
                    C[tmpri][j]^=C[ri][j];
                }
            }
        }
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
