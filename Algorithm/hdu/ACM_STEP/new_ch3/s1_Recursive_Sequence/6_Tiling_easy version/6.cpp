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
	
	__int64 f[50]={0,1,3};
	for(int i=3;i<=30;i++){
		f[i]=f[i-1]+2*f[i-2];
	}
	
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
