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

int gcd(int x,int y){
	if(x%y==0)return y;
	else {
		return gcd(y,x%y);
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int x,y;
	while(cin>>x>>y){
		#ifdef U_DEBUG
		cout<<gcd(x,y)<<endl;
		#endif
		cout<<x/gcd(x,y)*y<<endl;
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
