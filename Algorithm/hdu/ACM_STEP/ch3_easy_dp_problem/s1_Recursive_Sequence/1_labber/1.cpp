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

<<<<<<< HEAD
=======

>>>>>>> eef699ca292afba7548018746315cb434ba09bc7
int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
<<<<<<< HEAD
	
=======

>>>>>>> eef699ca292afba7548018746315cb434ba09bc7
	int f[50];
		f[1]=0;
		f[2]=1;
		f[3]=2;
		for(int i=4;i<=40;i++){
			f[i]=f[i-1]+f[i-2];
		}
<<<<<<< HEAD
		
=======

>>>>>>> eef699ca292afba7548018746315cb434ba09bc7
	int N;
	cin>>N;
	while(N--){
		int m;
		cin>>m;
		printf("%d\n",f[m]);
<<<<<<< HEAD
		
=======

>>>>>>> eef699ca292afba7548018746315cb434ba09bc7
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
