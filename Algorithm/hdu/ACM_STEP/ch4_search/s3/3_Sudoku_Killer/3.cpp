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

class CPos{
public:
	int ri;
	int ci;

	CPos(){
	}
	CPos(int a, int b){
		ri = a;
		ci = b;
	}
	CPos(const CPos &p){
		ri = p.ri;
		ci = p.ci;
	}
};


#define MAX_SIZE 10
int map[MAX_SIZE][MAX_SIZE];//1-9,  -1  means ?
CPos pos[100];
int posi = 0;
bool ansed;

bool Check(int cur, int num){
	bool res = true;
	//check row and col
	int ri = pos[cur].ri;
	int ci = pos[cur].ci;
	for (int di = 1; di <= 9; di++){
		if (map[ri][di] == num || map[di][ci] == num){
			return false;
		}
	}

	//check the grid
	ri = (ri - 1) / 3 * 3 + 1;
	ci = (ci - 1) / 3 * 3 + 1;
	for (int i = ri + 2; i >= ri; i--){
		for (int j = ci + 2; j >= ci; j--){
			if (map[i][j] == num)
				return false;
		}
	}

	return true;
}

int DFS(int place){
	
	if (place >= posi){
		ansed = true;
		for (int ri = 1; ri <= 9; ri++){
			printf("%d", map[ri][1]);
			for (int ci = 2; ci <= 9; ci++){
				printf(" %d", map[ri][ci]);
			}
			printf("\n");
		}
		return 0;
	}
		

	for (int num = 1; num <= 9; num++){

		if (Check(place, num) && (!ansed)){
			map[pos[place].ri][pos[place].ci] = num;
			DFS(place + 1);
			map[pos[place].ri][pos[place].ci] = -1;
		}

	}
	return 0;
}

int main(){
#ifdef L_JUDGE
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	char cmd[3];
	
	int ri = 1;
	int ci = 1;
	int pp = 0;
	posi = 0;
	ansed = false;
	while (EOF!=scanf("%s",cmd)){
		
		if (cmd[0] != '?'){
			map[ri][ci] = (cmd[0] - '0');
		}
		else{
			map[ri][ci] = -1;
			pos[posi].ri = ri;
			pos[posi].ci = ci;
			posi++;
		}
		ci++;
		if (ci > 9){
			ri++;
			ci = 1;
		}
		if (ri > 9){
			if (pp)printf("\n");
			else pp = 1;

			DFS(0);
			ri = 1;
			ci = 1;
			ansed = false;
			posi = 0;
		}
	}

#ifdef L_JUDGE
	fclose(stdin);
	fclose(stdout);
	system("out.txt");
#endif

	return 0;
}
