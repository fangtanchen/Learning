#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

void g(int a){
	if(a){
		g((a-1)/26);
		putchar((a-1)%26+'A');
	}
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;

	for(scanf("%d", &n);n--;){
		char s[55],  *p;
		int x, y;
		memset(s, 0, sizeof(s));
		scanf("%s", s);
		if(2==sscanf(s, "%*c%d%*c%d", &x, &y)){
			g(y);
			printf("%d\n", x);
		}else{
			int x=0;
			for(p=s;(*p)>64;p++){
				x=26*x+(*p)-64;
			}
			printf("R%sC%d\n", p, x);
			
		}

	}
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
