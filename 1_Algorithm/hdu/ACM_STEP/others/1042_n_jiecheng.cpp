#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int f[40000];
int flen=1;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	int N;
	while(EOF!=scanf("%d", &N)){
		flen=1;
		f[0]=1;
		for(int ni=2;ni<=N;ni++){
			int c=0;
			for(int li=0;li<flen;li++){
				f[li]=f[li]*ni+c;
				c=f[li]/10000;
				f[li]%=10000;
			}
			while(c){
				f[flen]=c%10000;
				c/=10000;
				flen++;
			}
		}

		printf("%d", f[flen-1]);
		for(int i=flen-2;i>=0;i--){
			printf("%04d", f[i]);
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
