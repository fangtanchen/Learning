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

long gcd(long x,long y){
	if(x%y==0)return y;
	else{
		return gcd(y,x%y);
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int T;
	cin>>T;
	while(T--){
		long a[2];
		long b[2];
		scanf("%ld/%ld %ld/%ld",&a[0],&a[1],&b[0],&b[1]);
		
		#ifdef U_DEBUG
			cout<<gcd(a[0],b[0])<<endl;
			cout<<gcd(a[1],b[1])<<endl;
		#endif
		
		int t=gcd(a[0],a[1]);
		a[0]/=t;
		a[1]/=t;
		
		t=gcd(b[0],b[1]);
		b[0]/=t;
		b[1]/=t;
		
		long x=a[0]/gcd(a[0],b[0])*b[0];
		long y=gcd(a[1],b[1]);
		
		
		cout<<x;
		if(y!=1)cout<<"/"<<y;
		cout<<endl;
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
