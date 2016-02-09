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
	int m,n;
	while(EOF!=scanf("%d%d",&m,&n)){
		if(m<n){
			printf("0\n");
			continue;
		}
		if(0==n){
			printf("1\n");
			continue;
		}
		
		int f[200];
		int len=1;
		f[0]=m+1-n;
		
		int imax=m+n;
		for(int i=m+2;i<=imax;i++){
			int c=0;
			for(int j=0;j<len;j++){
				int temp=f[j]*i+c;
				f[j]=temp%10000;
				c=temp/10000;
			}
			while(c){
				int temp=c;
				f[len]=temp%10000;
				c=temp/10000;
				len++;
			}
		}
		
		for(int i=n;i>=2;i--){
			int c=0;
			for(int j=len-1;j>=0;j--){
				int temp=c*10000+f[j];
				f[j]=temp/i;
				c=temp%i;
			}
			while(f[len-1]==0){
				len--;
			}
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
