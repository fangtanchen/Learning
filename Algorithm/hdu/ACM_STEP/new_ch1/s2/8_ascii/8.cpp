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
	
	int T;
	cin>>T;
	int num=0;
	char s[1010];
	for(int i=0;i<T;i++){
		cin>>num;
		s[i]=num;
	}
	s[T]=0;
	cout<<s;
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
