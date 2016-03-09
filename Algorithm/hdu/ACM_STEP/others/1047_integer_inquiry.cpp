#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)a
#endif

using namespace std;

char ans[500];
char a[500];

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	scanf("%d", &N);
	while (N--){
		memset(ans, '0', sizeof(ans));
		int ans_len = 1;
		while (gets(a), strcmp(a, "0")){
			int len = strlen(a);
			int c = 0;
			int i, j;
			for (i = 0, j = len - 1;
				(j >= 0) && (i < ans_len); i++, j--){
				int temp= ans[i] + c + a[j] - 96;
				ans[i] = temp % 10 + '0';
				c = temp / 10;
			}
			for (; i < ans_len &&(c); i++){
				int temp = ans[i] + c - '0';
				ans[i] = temp % 10 + '0';
				c = temp / 10;
			}
			while (j >= 0){
				int temp = a[j] + c - '0';
				ans[ans_len++] = temp % 10 + '0';
				c = temp / 10;
				j--;
			}
			while (c){
				ans[ans_len++] = c % 10 + '0';
				c /= 10;
			}
		}
		for (int i = ans_len - 1; i >= 0; i--){
			printf("%c", ans[i]);
		}
		printf("\n");
		if (N)printf("\n");
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
