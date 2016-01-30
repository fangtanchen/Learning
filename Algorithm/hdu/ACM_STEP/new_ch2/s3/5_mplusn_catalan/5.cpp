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
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int m, n;
	int casei = 1;
	while (cin >> m >> n, m || n){
		printf("Test #%d:\n", casei++);
		if (n>m){
			printf("0\n");
			continue;
		}
		int f[1000];
		memset(f, 0, sizeof(f));
		int len = 1;
		f[0] = m - n + 1;
		int imax = m + n;	
		for (int i = 2; i <= imax; i++){
			//if (i == (m + 1))continue;
			int c = 0;
			for (int j = 0; j<len; j++){
				int temp = f[j] * i + c;
				f[j] = temp % 10000;
				c = temp / 10000;
			}
			while (c){
				int temp = c + f[len];
				f[len] = temp % 10000;
				c = temp / 10000;
				len++;
			}
		}
		
		{
			int i=m+1;
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
		

		printf("%d", f[len - 1]);
		for (int i = len - 2; i >= 0; i--){
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
