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

int ha[1000010];
int in[1000010];
int out[1000010];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int casei=1;
	int a, b;
	bool ans=true;;
	int inlen=0;
	int outlen=0;
	
	while(1){
		ans=true;
		memset(in, 0, sizeof(in));
		memset(out, 0, sizeof(out));
		memset(ha, -1, sizeof(ha));
		int hai=0;

		while(EOF!=scanf("%d%d", &a, &b), (a>0)&&(b>0)){
			if(-1==ha[a]){
				ha[a]=hai;
				hai++;
			}
			if(-1==ha[b]){
				ha[b]=hai;
				hai++;
			}
			in[ha[b]]++;
			out[ha[a]]++;
		}

		if((a<0)&&(b<0))break;

		int sum=0;
		for(int i=0;i<hai;i++){
			if(in[i]>1){
				ans=false;
				break;
			}
			sum+=in[i];
		}
		if(sum<hai-1)ans=false;
		if(ans)printf("Case %d is a tree.\n", casei++);
		else printf("Case %d is not a tree.\n", casei++);
	}


	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
