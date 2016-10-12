#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

char in[1200];
int num[1200];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
	
	while(EOF!=scanf("%s", in)){
		int si=0;
		int in_len=strlen(in)-1;
		int numi=-1;
		memset(num, 0, sizeof(num));

		while(si<in_len){
			for(;('5'==in[si])&&(si<=in_len);si++)
				;
			if(si<=in_len){
				numi++;
			}
			for(;('5'!=in[si])&&(si<=in_len);si++){
				num[numi]=num[numi]*10+in[si]-'0';
			}

		}
		sort(num, num+numi+1);
		printf("%d", num[0]);
		for(int i=1;i<=numi;i++){
			printf(" %d", num[i]);
		}
		printf("\n");
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
