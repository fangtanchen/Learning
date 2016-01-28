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
	int T;
	cin>>T;
	while(T--){
		int m,p,q;
		int f[100];
		int a;
		int N;
		cin>>N;
		cin>>m;
		while(m--){
			cin>>a;
			f[a]=1;
		}
		cin>>p;
		while(p--){
			cin>>a;
			f[a]=2;
		}
		cin>>q;
		while(q--){
			cin>>a;
			f[a]=3;
		}
		
		#ifdef U_DEBUG
		for(int i=N;i>0;i--){
			cout<<f[i]<<" ";
		}
		cout<<endl;
		#endif
		
		//ÉèÖÃ½ûÖ¹Î»ÖÃ
		int cf=2;
		int flag=true;
		for(int i=N;i>0;i--){
			if(f[i]==cf){
				flag=false;
				break;
			}
			cf=6-cf-f[i];
		}
		if(flag)printf("true\n");
		else printf("false\n");
		
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
