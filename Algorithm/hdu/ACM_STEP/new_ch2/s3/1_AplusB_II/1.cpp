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
	for(int Ti=1;Ti<=T;Ti++){
		if(Ti!=1)printf("\n");
		char A[1010];
		char B[1010];
		scanf("%s %s",A,B);
		
		int alen=strlen(A);
		int blen=strlen(B);
		char C[1010];
		int clen=(alen>blen?alen:blen);
		C[clen]=0;
		int ai=alen-1;
		int bi=blen-1;
		int ci=clen-1;
		int c=0;
		for(;ai>=0&&bi>=0;ai--,bi--,ci--){
			int temp=A[ai]+B[bi]-96+c;
			C[ci]=temp%10+48;
			c=temp/10;
		}
		while(ai>=0){
			int temp=A[ai]-'0'+c;
			C[ci]=temp%10+'0';
			c=temp/10;
			ci--;
			ai--;
		}
		while(bi>=0){
			int temp=B[bi]-'0'+c;
			C[ci]=temp%10+'0';
			c=temp/10;
			ci--;
			bi--;
		}
		printf("Case %d:\n",Ti);
		printf("%s + %s = ",A,B);
		if(c)cout<<1;
		printf("%s\n",C);
	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
