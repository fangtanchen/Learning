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

char pre[40], in[40];

void post_order(int ps, int pd, int is, int id){
	if(ps>pd){
		return;
	}
	int llen;
	for(llen=is;llen<=id;llen++){
		if(in[llen]==pre[ps])break;
	}
	llen-=is;
	post_order(ps+1, ps+llen, is, is+llen-1);
	post_order(ps+llen+1, pd, is+llen+1, id);
	printf("%c", pre[ps]);
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	scanf("%s", pre);
	scanf("%s", in);
	int len=strlen(pre)-1;
	post_order(0, len, 0, len);
	printf("\n");

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
