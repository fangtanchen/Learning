#include<iostream>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int cmp(int x, int y){
	if (x<y)return true;
	else return false;
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int a[4];
	int res[30];
	int flag = 1;
	while (cin >> a[0] >> a[1] >> a[2] >> a[3], a[0] || a[1] || a[2] || a[3]){
		if (flag){
			flag = 0;
		}
		else{
			cout << endl;
		}

		sort(a, a + 4, cmp);

#ifdef U_DEBUG
		for (int i = 0; i<4; i++){
			{
				cout << a[i] << " ";
			}
			cout << endl;
		}
		cout << endl << endl;
#endif

		int pi = 0;
		for (int i = 0; i < 4; i++) {
			//if(a[i]==0)continue;			
			for (int j = 0; (j < 4); j++){
				if (j == i)continue;
				for (int k = 0; (k < 4); k++){
					if ((i == k) || (j == k))continue;
					int t = 6 - i - j - k;
					res[pi] = a[i] * 1000 + a[j] * 100 + a[k] * 10 + a[t];
					pi++;
				}
			}
		}


		{
			sort(res, res + 24, cmp);
		}


		int ans[4][6];
		memset(ans, 0, sizeof(ans));
		int ansi = 0;
		int ansj = 0;
		for (int i = 0; i < 23; i++){
			if (res[i] < 1000)continue;
			if (res[i] == res[i + 1])continue;
			ans[ansi][ansj] = res[i];
			ansj++;
			if (res[i] / 1000 != res[i + 1] / 1000){
				ansi++;
				ansj = 0;
			}
		}
		ans[ansi][ansj] = res[23];

		for (int i = 0; i <= ansi; i++){
			cout << ans[i][0];
			for (int j = 1; j < 6; j++){
				if (ans[i][j] != 0){
					cout << " "<<ans[i][j];
				}
				else{
					break;
				}
			}
			cout << endl;
		}

	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
