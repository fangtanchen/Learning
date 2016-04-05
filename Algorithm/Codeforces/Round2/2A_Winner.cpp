#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<map>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

string a[1001];
int b[1001];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	map<string, int> mp;
	map<string, int> mk;
	while(EOF!=scanf("%d", &n)){
		mp.clear();
		mk.clear();
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			mp[a[i]]+=b[i];
		}
		int max=-10000;
		for(map<string, int>::iterator it=mp.begin();
				it!=mp.end();it++){
			int t=it->second;
			if(max<t)
				max=t;
			
		}

		for(int i=0;i<n;i++){
			mk[a[i]]+=b[i];
			if((mk[a[i]]>= max)
					&&(mp[a[i]]== max)){
				cout<<a[i]<<endl;
				break;
			}
		}
	}

	

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
