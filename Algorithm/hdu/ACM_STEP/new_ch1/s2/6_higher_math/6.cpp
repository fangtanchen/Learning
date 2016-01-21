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
	cin>>n;
	for(int ti=1;ti<=n;ti++){
		printf("Scenario #%d:\n",ti);
		
		int a,b,c;
		cin>>a>>b>>c;
		if(a*a==b*b+c*c
		||b*b==a*a+c*c||
		c*c==a*a+b*b){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
		cout<<endl;
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
