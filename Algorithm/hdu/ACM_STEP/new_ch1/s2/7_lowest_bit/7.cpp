#include<iostream>
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
	
	int a=0x0001;
	int n;
	while(cin>>n,n){
		a=0x0001;
		while((n&a)==0){
			a=a<<1;
			#ifdef U_DEBUG
				cout<<a<<endl;
			#endif
		}
		cout<<a<<endl;
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
