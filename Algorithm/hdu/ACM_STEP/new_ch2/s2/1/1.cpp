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
	
	int fib[21]={0,1};
	for(int i=2;i<21;i++){
		fib[i]=fib[i-1]+fib[i-2];
	}
	
	double tu=(1+sqrt(5.0))/2.0;
	int n;
	while(EOF!=scanf("%d",&n)){
		if(n<21){
			printf("%d\n",fib[n]);
			continue;
		}
		
		double p=-0.5*log10(5)+n*log10(tu);
		double tes=p-(int)p;
		int ans=pow(10,tes)*1000;
		printf("%d\n",ans);
	}
	

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
