#include<iostream>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

__int64 gcd(__int64 x, __int64 y){
	if (x%y == 0)return y;
	else return gcd(y, x%y);
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	int N;
	cin >> N;
	cin.ignore();
	while (N--){
		char str[20];
		scanf("%s", str);
		int m, n;
		int i;
		int flag = 0;
		int len = strlen(str);
		if ( len<=2 ){
			printf("0/1\n");
			continue;
		}

		for (i = 2; i<len; i++){
			if (str[i] == '('){
				flag = 1;
				break;
			}
		}
		if (i>=len){
			n = 0;
			m = i - 2;
		}
		else{
			m = i - 2;
			n = strlen(str) - 4 - m;
		}
		int a, b;
		if (m==0){
			sscanf(str, "0.(%d)", &b);
			a = 0;
		}
		else if(n==0){
			sscanf(str, "0.%d", &a);
			b = 0;			
		}
		else{
			sscanf(str, "0.%d(%d)",&a, &b);
		}

#ifdef U_DEBUG
		cout << "a:" << a << " b:" << b << " m:" << m << " n:" << n << endl;
#endif

		__int64 m1= 1;
		__int64 n1 = 1;
		for (int i = 0; i < m; i++)
		{
			m1 *= 10;
		}
		for (int i = 0; i < n; i++)
		{
			n1 *= 10;
		}
		if (0 == b){ 			
			if (0 == a){
				printf("0/1\n");
				continue;
			}
			n1 = 2;
		}
		__int64 x1 = a*(n1 - 1) + b;
		__int64 y1 = m1*(n1 - 1);
		__int64 z = gcd(x1, y1);
		printf("%I64d/%I64d\n", x1 / z, y1 / z);
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
