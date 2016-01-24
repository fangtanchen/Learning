#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cmath>
//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int T=0;
	scanf("%d",&T);
	while(T--){
		int n; 
		scanf("%d",&n);
		if(1==n){
			printf("0\n");
			continue;
		}
		int res=1;		
		
		int max=sqrt(n)+1;
		for(int i=2;i<max;i++){
			if(n%i==0){
				int t=n/i;
				res=res+i;
				if(i!=t)res+=t;
			}
		}
		printf("%d\n",res);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
