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
	__int64 f[55];
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=50;i++){
		f[i]=f[i-1]+f[i-2];
	}
	
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%I64d\n",f[n]);
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
