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

int f[1000010];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int L,M;
	while(EOF!=scanf("%d%d",&L,&M)){
		f[0]=0;
		f[1]=2%M;
		f[2]=4%M;
		f[3]=6%M;
		f[4]=9%M;
		f[5]=15%M;
		for(int i=6;i<=L;i++){
			f[i]=f[i-2]+f[i-3]+2*f[i-4]+f[i-5];
			f[i]=f[i]%M;
		}
		printf("%d\n",f[L]);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
