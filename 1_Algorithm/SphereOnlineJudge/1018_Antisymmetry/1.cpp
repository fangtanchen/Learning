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
const int MAXN=5e5+10;
const int MODU1=1e9+7,MODU2=9999971;

char str[MAXN];
int N;

long long int f1[MAXN],f2[MAXN],a1[MAXN],a2[MAXN],to1[MAXN],to2[MAXN];



int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    scanf("%s",str);

    to1[0]=to2[0]=1;
    for(int i=1;i<=N;i++){
        to1[i]=2*to1[i-1]%MODU1;
        to2[i]=2*to2[i-1]%MODU2;
    }
    f1[0]=f2[0]=0;
    for(int i=1;i<=N;i++){
         f1[i]=2*f1[i-1]+str[i-1]-'0';
         f1[i]%=MODU1;
         f2[i]=2*f2[i-1]+str[i-1]-'0';
         f2[i]%=MODU2;
    }
    a1[N+1]=a2[N+1]=0;
    for(int i=N;i;i--){
        a1[i]=2*a1[i+1]+((str[i-1]-'0')^1);
        a1[i]%=MODU1;
        a2[i]=2*a2[i+1]+((str[i-1]-'0')^1);
        a2[i]%=MODU2;
    }
    long long ans=0;
    for(int i=1;i<=N;i++){
        int l=0,r=min(i,N-i)+1;
        while(l+1<r){
             int mid=(l+r)>>1;
             if((f1[i]-f1[i-mid]*to1[mid]%MODU1+MODU1)%MODU1
                     ==(a1[i+1]-a1[i+1+mid]*to1[mid]%MODU1+MODU1)%MODU1
                     &&((f2[i]-f2[i-mid]*to2[mid]%MODU2+MODU2)%MODU2
                         ==(a2[i+1]-a2[1+i+mid]*to2[mid]%MODU2+MODU2)%MODU2)
               ){
                  l=mid;
             }else{
                 r=mid;
             }
        }
        ans+=l;
    }
    printf("%lld\n",ans);

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
