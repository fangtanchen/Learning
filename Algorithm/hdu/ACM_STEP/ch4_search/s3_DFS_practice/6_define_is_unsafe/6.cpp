#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#include<string>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


int str[1000000];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int T;
	scanf("%d",&T);
	while(T--){
		vector<string>	max_stack;
		vector<string>  op_stack;
		vector<string> num_stack;

		scanf("%s",str);
		int sti=0;
		int pti=0;
		int imax=strlen(str);
		for(pti=0;pti<imax;pti++){
			if(str[pti]=='M'){
				
			}
		
		}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
