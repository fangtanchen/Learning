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
__int64 f[500010];
int main(){
	
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	for(int i=1;i<250001;i++){
		for(int j=i+i;j<500003;j+=i){
			f[j]=f[j]+i;
		}
	}
	
	int T=0;
	scanf("%d",&T);
	while(T--){
		int n; 
		scanf("%d",&n);
		printf("%I64d\n",f[n]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
