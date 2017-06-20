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

int a,b;
int primelist[MAXN];
int pcnt;
bool isPrime[MAXN];

void Init(){
     pcnt=0;
     memset(isPrime,true,sizeof(isPrime));
     isPrime[1]=false;
     for(int i=2;i<MAXN;i++){
         if(isPrime[i]){
              primelist[pcnt++]=i;
         }
         for(int pi=0;pi<pcnt;pi++){
             int tmp=primelist[pi]*i;
             if(tmp>=MAXN)break;
             isPrime[tmp]=false;
             if(i%primelist[pi]==0)break;
         }
     }
}

int Fac(int a,int b){
    int ret=a;
    int t=1;
    int x=0;
    while(b){
        x=t*a;
        ret=x;
        while((b>0)&&(x%a==0)){
            x/=a;
            b--;
        }
        t++;
    }
    return ret;
}

int F(int x){
    int tmpx=x;
    int ret=1;
    for(int pi=0;pi<pcnt;pi++){
        if(primelist[pi]*primelist[pi]>tmpx)break;
        int cnt=0;
        if(tmpx%primelist[pi]==0){
            while(tmpx%primelist[pi]==0){
                tmpx/=primelist[pi];
                cnt++;
            }
        }
        if(cnt){
             ret=max(ret,Fac(primelist[pi],cnt));
        }
    }
    if(tmpx!=1)ret=max(ret,tmpx);
    return ret;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    cin>>a>>b;
    Init();
    cout<<max(0,F(b)-F(a))<<endl;

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
