#include<iostream>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
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
	
	int n;
	while(cin>>n,n){
		int sum=0;
		int a=0;
		while(n--){
			cin>>a;
			sum+=a;
		}
		cout<<sum<<endl;
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
