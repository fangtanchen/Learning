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

	char str[10];
	int n;
	while (EOF != scanf("%s %d", str, &n)){
#ifdef U_DEBUG
		printf("%s--%d\n", str, n);
#endif

		if (0 == n){
			printf("1\n");
			continue;
		}

		int ntemp = n;
		int num[3][200];
		int len[3] = { 0, 0, 0 };

		int ft_flag = 0;
		int ft_pos = 0;

		int starti = 0;
		int endi = 5;

		for (int i = 0; i<6; i++){
			if (str[i] == '.'){
				ft_flag = 1;
				break;
			}
		}

		for (; str[endi] == '0'; endi--)
			;

		for (starti = 0; str[starti] == '0'; starti++)
			;

		if (ft_flag)	{
			if (str[endi] == '.'){
				ft_pos = 0;
			}
			else{
				for (int ei = endi - 1; ei >= 0; ei--){
					if (str[ei] == '.'){
						ft_pos = endi - ei;
						break;
					}
				}
			}
			if (str[starti] == '.'){
				for (starti = starti + 1; str[starti] == '0'; starti++)
					;
			}
		}
		else{
			endi = 5;
		}

		if ((starti>endi)
			|| ((starti == endi) && (str[starti] == '.'))){
			printf("0\n");
			continue;
		}

		for (int i = endi; i >= starti; i--){
			if (str[i] == '.'){				
				continue;
			}
			num[0][len[0]] = str[i] - '0';
			len[0]++;
		}


#ifdef U_DEBUG
		printf("\ntest deal with the input:\n");
		printf("origin number: %s\n", str);
		printf("  deal number: ");
		for (int i = len[0] - 1; i >= 0; i--) {
			printf("%d", num[0][i]);
		}
		printf("\nft_pos: %d", ft_pos);
		printf("\n\n");
#endif

		//有浮点数和没浮点 000099 和99.000是不一样的 
		int sr = 1;
		int dr = 2;
		len[sr] = len[0];
		for (int i = 0; i<len[0]; i++){
			num[sr][i] = num[0][i];
		}

		while (n>1){
			int di = 0;
			memset(num[dr], 0, sizeof(num[dr]));
			len[dr] = 0;
			for (int i = 0; i<len[0]; i++){
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
				while (c){
					int temp = num[dr][di] + c;
					num[dr][di] = temp % 10;
					c = temp / 10;
					di++;

				}
				if (len[dr]<di)len[dr] = di;
			}
			n -= 1;
			sr = 3 - sr;
			dr = 3 - dr;
		}

#ifdef U_DEBUG
		for (int i = len[sr] - 1; i >= 0; i--){
			printf("%d", num[sr][i]);
		}
		printf("\n\n\n");
#endif

		int pp = ft_pos*ntemp;
		int ppi = 0;
		{
			for (ppi = len[sr] - 1; ppi >= pp; ppi--){
				printf("%d", num[sr][ppi]);
			}
		}
		if (pp != 0){
			printf(".");
			for (; pp > len[sr]; pp--){
				printf("0");
			}
			for (ppi = pp - 1; ppi >= 0; ppi--){
				printf("%d", num[sr][ppi]);
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
