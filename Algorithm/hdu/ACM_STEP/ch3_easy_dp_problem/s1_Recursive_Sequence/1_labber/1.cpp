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

	int f[50];
		f[1]=0;
		f[2]=1;
		f[3]=2;
		for(int i=4;i<=40;i++){
			f[i]=f[i-1]+f[i-2];
		}

	int N;
	cin>>N;
	while(N--){
		int m;
		cin>>m;
		printf("%d\n",f[m]);

	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
