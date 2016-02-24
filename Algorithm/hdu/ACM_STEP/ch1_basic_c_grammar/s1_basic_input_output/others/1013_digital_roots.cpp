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

char N[10010];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
//	int N;
	while(EOF!=scanf("%s", N), !((strlen(N)==1) &&(N[0]=='0'))){
		int sum=0;
		for(int i=strlen(N)-1;i>=0;i--){
			sum=sum+N[i]-48;
		}
		int temp;
		do{
			temp=sum;
			sum=0;
			while(temp){
				sum=sum+temp%10;
				temp/=10;
			}
		}while(sum>9);
		printf("%d\n", sum);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
