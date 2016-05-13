#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>


#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

bool prime[1000009];
int primeList[200000];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
    int n=0;
    scanf("%d",&n);
    int cnt=0;
    memset(prime,true,sizeof(prime));
    for(int i=2;i<=n;i++){
        if(prime[i]){
            primeList[cnt]=i;
            cnt++;
        }
        for(int j=0;j<cnt;j++){
            int temp=i*primeList[j];
            if(temp>n)break;
             prime[temp]=false;
             if(i%primeList[j]==0)break;
        }
    }
    printf("%d\n",cnt);
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
