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
	
	int n;
	int f[2000];
	while(cin>>n){
		int len=1;
		f[0]=1;
		int imax=2*n;
		for(int i=n+2;i<=imax;i++){
			int c=0;
			for(int j=0;j<len;j++){
				int temp=f[j]*i+c;
				f[j]=temp%10000;
				c=temp/10000;
			}
			if(c){
				f[len]=c;
				len++;
			}
		}
		
		for(int i=2;i<=n;i++){
			int c=0;
			for(int j=len-1;j>=0;j--){
				int temp=c*10000+f[j];
				f[j]=temp/i;
				c=temp%i;
			}
			for(;f[len-1]==0;len--)
				;
		}
		
		printf("%d",f[len-1]);
		for(int i=len-2;i>=0;i--){
			printf("%04d",f[i]);
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
