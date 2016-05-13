#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

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
	__int64 f[60]={0,1,2,3,4};
	for(int i=5;i<=55;i++){
		f[i]=f[i-1]+f[i-3];
	}	
	int n;
	while(scanf("%d",&n)!=EOF,n){
		printf("%I64d\n",f[n]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
