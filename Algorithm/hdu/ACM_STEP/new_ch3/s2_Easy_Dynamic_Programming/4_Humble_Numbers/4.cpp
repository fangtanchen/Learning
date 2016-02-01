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

	int f[5900] = { 0, 1, 2, 3, 4,
		5, 6, 7, 8, 9,
		10, 12, 14, 15,
		16, 18, 20, 21, 24, 25, 27 };

	int pt[4] = { 1, 1, 1, 1 };
	int ba[4] = { 2, 3, 5, 7 };
	for (int i = 2; i <= 5843; i++){
		int min = f[pt[0]] * 2;
		int temp[4];
		temp[0] = min;
		for (int p = 1; p<4; p++){
			temp[p] = (f[pt[p]]) * (ba[p]);
			if (min>temp[p])min = temp[p];
		}
		f[i] = min;
		for (int p = 0; p<4; p++){
			if (min == temp[p]){
				pt[p] += 1;
			}
		}
	}

	int n;
	while (EOF != scanf("%d", &n), n){
		printf("The %d", n);
		int tt = n % 100;
		if (tt>3 && tt <= 20){
			printf("th");
		}
		else{
			tt = tt % 10;
			switch (tt){
			case 1:
				printf("st");
				break;
			case 2:
				printf("nd");
				break;
			case 3:
				printf("rd");
				break;
			default:
				printf("th");
				break;
			}
		}
		printf(" humble number is %d.\n", f[n]);
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
