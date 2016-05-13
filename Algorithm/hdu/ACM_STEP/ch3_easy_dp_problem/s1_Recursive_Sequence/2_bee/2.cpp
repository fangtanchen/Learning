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

	long long f[55];
	f[0]=0;
	f[1]=1;
	f[2]=2;
	for(int i=3;i<=48;i++){
		f[i]=f[i-1]+f[i-2];
	}
	int N;
	cin>>N;
	while(N--){
		int a,b;
		cin>>a>>b;
		int m=b-a;
		printf("%lld\n",f[m]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
