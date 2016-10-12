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

int N;
int ans;
#define MAX_SIZE 30
int pcol[MAX_SIZE];
int ptri1[MAX_SIZE];
int ptri2[MAX_SIZE];


int DFS(int ri){
	
	if(ri==N+1){
		ans++;
		return 0;
	}

	for(int ci=1;ci<=N;ci++){
		//check
		bool flag=true;
		for(int pi=1;pi<ri;pi++){
			if(ci==pcol[pi]
			||(ci-ri==ptri1[pi])
			||(ci+ri==ptri2[pi]))
			  flag=false;
		}
		if(flag){
			pcol[ri]=ci;
			ptri1[ri]=ci-ri;
			ptri2[ri]=ci+ri;
			DFS(ri+1);
		}
	}

	return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int pp[15];
	for(N=1;N<=10;N++){
		ans=0;
		DFS(1);
		pp[N]=ans;
	}
	while(scanf("%d",&N),N){
		printf("%d\n",pp[N]);
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
