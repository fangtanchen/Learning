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

int gcd(int x,int y){
	if(x%y==0)return y;
	else return gcd(y,x%y);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int P;
	cin>>P;
	while(P--){
		int m,n;
		cin>>m>>n;
		int res=gcd(m,n);
		if(res==1){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
		
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
