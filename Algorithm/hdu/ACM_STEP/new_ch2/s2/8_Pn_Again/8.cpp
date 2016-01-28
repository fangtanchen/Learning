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
	
	int f[2010]={1,1,2};
	int s=1;
	for(int i=2;i<49;i++){
		f[i]=(f[i-1]*i)%2009;
	}
	
	#ifdef U_DEBUG
	for(int i=0;i<49;i++){
		printf("%d ",f[i]);
	}
	#endif
	
	int n;
	while(EOF!=scanf("%d",&n)){
		if(n>=49)printf("0\n");
		else printf("%d\n",f[n]);
	}
	
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
