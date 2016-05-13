#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;


int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	char str[10];
	int n;
	while (EOF != scanf("%s %d", str, &n)){
#ifdef U_DEBUG
		printf("%s--%d\n", str, n);
#endif
		
		if(0==n){
			printf("1\n");
			continue;
		}
		
		int num[3][200];
		int len[3] = { 5, 5, 1 };

		int pf = 6;
		int flag = 0;
		for (int i = 0; i<6; i++){
			if (str[i] == '.'){
				pf = i;
				flag = 1;
			}
			else{
				num[1][4 - i + flag] = num[0][4 - i + flag] = str[i] - '0';
			}
		}
		
		
		int pte=0;
		for(int i=0;i<5;i++){
			pte=pte+num[0][i];
		}
		
		int former=pf;
		int latter=5-pf;
		if(pf==6){
			latter=0;
		}
		latter=latter*n;
		
#ifdef U_DEBUG
		cout << "num array:" << endl;
		for (int i = 4; i >= 0; i--){
			cout << num[0][i] << num[1][i];
		}
		cout << endl;
#endif

		int dr = 2;
		int sr = 1;
		while (n>1){
		/*	if (n % 2 == 0){
				int di = 0;
				memset(num[dr], 0, sizeof(num[dr]));
				len[dr] = 0;
				for (int i = 0; i<len[sr]; i++){
					di = i;
					int c = 0;
					if (num[sr][i] == 0){
						continue;
					}
					for (int j = 0; j<len[sr]; j++){
						int temp = num[dr][di] + num[sr][i] * num[sr][j] + c;
						num[dr][di] = temp % 10;
						c = temp / 10;
						di++;
					}
					while (c){
						int temp== num[dr][di]+c;
						num[dr][di] =temp%10;
						c=temp/10;
						di++;
					}
					if (di>len[dr])len[dr] = di;
				}
				n /= 2;
				sr = 3 - sr;
				dr = 3 - dr;
			}
			else{*/
				int di = 0;
				memset(num[dr], 0, sizeof(num[dr]));
				len[dr] = 0;
				for (int i = 0; i<5; i++){
					if (num[0][i] == 0){
						continue;
					}
					di = i;
					int c = 0;
					for (int j = 0; j<len[sr]; j++){
						int temp = num[dr][di] + num[sr][j] * num[0][i] + c;
						num[dr][di] = temp % 10;
						c = temp / 10;
						di++;
					}
					while(c){
						int temp=num[dr][di]+c;
						num[dr][di] = temp%10;
						c=temp/10;
						di++;
						/*num[dr][di]=c;
						di++;*/
					}
					if (len[dr]<di)len[dr] = di;
				}
				n -= 1;
				sr = 3 - sr;
				dr = 3 - dr;
			//}
		}
#ifdef U_DEBUG
		for (int i = len[sr]-1; i >= 0; i--){
			printf("%d", num[sr][i]);
		}
		printf("\n\n\n");
#endif
		int start1=len[sr]-1;
		for(;num[sr][start1]==0;start1--)
		  ;
		int end1=0;
		for(;num[sr][end1]==0;end1++)
		  ;
		

		for(int i=start1;i>=latter;i--){
			printf("%d",num[sr][i]);
		}
		
		if(latter>end1){
			printf(".");
			for(int i=latter-1;i>=end1;i--){
				printf("%d",num[sr][i]);
			}
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
