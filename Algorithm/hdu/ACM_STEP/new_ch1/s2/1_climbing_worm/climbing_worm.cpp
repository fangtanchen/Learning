#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<cstdlib>

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

	int n,u,d;
	while(cin>>n>>u>>d,n)
	{
		int res=1;
		n=n-u;
		while(n>0){
			n+=d;
			n-=u;
			res+=2;
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
