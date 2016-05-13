#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<set>
#include<string>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

set<string> st;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	string a, b;
	map<string, string> mp;
	while(EOF!=scanf("%d", &n), n){
		st.clear();
		mp.clear();
		for(int i=1;i<=n;i++){
			cin>>a>>b;
			st.insert(a);
			st.insert(b);
			mp[b]=a;
		}
		set<string>::iterator it;
		int tt=0;
		for(it=st.begin();it!=st.end();it++){
			if(mp[*it].length()==0){
				tt++;
			}
		}
		if(tt==1){
			printf("Yes\n");
		}else{
			printf("No\n");
		}

	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
