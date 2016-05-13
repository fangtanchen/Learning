#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<set>

#define U_DEBUG
#define L_JUDGE

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
	while(scanf("%d", &n), n){
		string a, b;
		set<string> st;
		set<string> mp;
		for(int i=0;i<n;i++){
			cin>>a>>b;
			st.insert(a);
			st.insert(b);
			mp.insert(b);

		}
		if(st.size()-mp.size()==1)printf("Yes\n");
		else printf("No\n");
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
