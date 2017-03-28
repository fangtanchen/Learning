#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<cmath>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
typedef long long LL;
const int MODU=1e9+7;
const int INF=1e9+10;
const double  esp=1e-8;
const int MAXN=1e5+10;


int T,N;

int Pow(int x,int y){
     int ret=1;
     while(y){
         if(1&y)ret=(LL)ret*x%MODU;
         y>>=1;
         x=(LL)x*x%MODU;
     }
     return ret;
}

int prime[MAXN],primenum;
void init_prime(int Max_Prime){
     primenum=0;
     prime[primenum++]=2;
     for(int i=3;i<=Max_Prime;i+=2){
         for(int j=0;j<primenum;j++){
             if(i%prime[j]==0)break;
             else if(prime[j]>sqrt((double)i)||j==primenum-1){
                  prime[primenum++]=i;
                  break;
             }
         }
     }
}

void add(int &x,int y){
     x+=y;
     if(x>=MODU)x-=MODU;
}

void Solve(int x,vector<int> &Pri,vector<int> &Num){
     Pri.clear();Num.clear();
     while(!(x&1))x>>=1;
     for(int i=1;(LL)prime[i]*prime[i]<=x;i++){
         if(x%prime[i])continue;
         Pri.push_back(prime[i]);
         Num.push_back(0);
         while(x%prime[i]==0)x/=prime[i],Num[Num.size()-1]++;
     }
     if(x!=1&&(x&1))Pri.push_back(x),Num.push_back(1);
}

vector<int> _pri,_num;

void cal(int id,int mul,int siz,int sor,int &now){
    if(id==_pri.size()){
        if(1==mul)return;
        if(1&siz)now+=sor/mul;
        else now-=sor/mul;
        return;
    }
    cal(id+1,mul,siz,sor,now);
    cal(id+1,mul*_pri[id],siz+1,sor,now);
}

int phi(int x){
     if(1==x)return 1;
     Solve(x,_pri,_num);
     int now=0;
     cal(0,1,0,x,now);
     return x-now;
}

int ans,n;
vector<int> pri,num;

void dfs(int id,int d){
    if(id==pri.size()){
        add(ans,(LL)Pow(2,n/d)*phi(d)%MODU);
        return;
    }
    for(int i=0;i<=num[id];i++){
         dfs(id+1,d);
         d*=pri[id];
    }
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    init_prime(1e5);
    int T;cin>>T;
    while(T--){
         cin>>n;
         Solve(n,pri,num);
         ans=0;
         dfs(0,1);
         printf("%lld\n",(LL)ans*Pow(n,MODU-2)%MODU);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
