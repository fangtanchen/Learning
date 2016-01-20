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
	
	int n;
	cin>>n;
	while(n--){
		int r,e,c;
		cin>>r>>e>>c;
		e=e-c;
#ifdef U_DEBUG
	cout<<r<<" "<<e<<" "<<c<<" "<<endl;
#endif

		if(r>e){
			cout<<"do not advertise"<<endl;
		}
		else if(r==e){
			cout<<"does not matter"<<endl;
		}
		else{
			cout<<"advertise"<<endl;
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
