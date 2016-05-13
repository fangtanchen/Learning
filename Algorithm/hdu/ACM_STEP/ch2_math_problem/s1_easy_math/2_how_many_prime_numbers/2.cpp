#include<iostream>
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

bool isprime(long x){
	long max=(long)sqrt(x);
	for(int i=2;i<=max;i++){
		if(x%i==0)return false;
	}
	return true;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	long n;
	long a;
	while(cin>>n){
		int res=0;
		for(int i=0;i<n;i++){
			cin>>a;
			res=res+isprime(a);
		}
		cout<<res<<endl;
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
