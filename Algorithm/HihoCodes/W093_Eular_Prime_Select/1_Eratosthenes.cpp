#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>


#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

bool prime[1000009];

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
             cnt++;
             int temp=i;
             while(temp<=n){
                 prime[temp]=false;
                 temp+=i;
             }
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
