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

#define MAX 402
int fa[MAX], fb[MAX];
int ta[MAX], tb[MAX];
int talen=0, tblen;
int falen, fblen;
char in_a[MAX], in_b[MAX];

int init(){
	memset(fa, 0, sizeof(fa));
	memset(fb, 0, sizeof(fb));
	memset(ta, 0, sizeof(ta));
	memset(tb, 0, sizeof(tb));

	falen=fblen=400;
	talen=tblen=400;

	return 0;
}

int split_input(char* s, int* t, int *f){
	int len=strlen(s);
	int pos=-1;
	for(int i=0;i<len;i++){
		if(s[i]=='.'){
			pos=i;
			s[i]=' ';
			break;
		}
	}
	char tempa[MAX]="";
	char tempb[MAX]="";
	if(pos>0){
		sscanf(s, "%s%s", tempa, tempb);
	}else if(pos==0){
		sscanf(s, "%s", tempb);
	}else{
		sscanf(s, "%s", tempa);
	}
	len=strlen(tempa);
	for(int i=len-1, j=400;i>=0;i--, j--){
		t[j]=tempa[i]-'0';
	}
	len=strlen(tempb);
	for(int i=0;i<len;i++){
		f[i]=tempb[i]-'0';
	}
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%s%s", in_a, in_b)){
		init();
		split_input(in_a, ta, fa);
		split_input(in_b, tb, fb);

		int c=0;
		for(int i=400;i>=0;i--){
			fa[i]=fa[i]+fb[i]+c;
			c=fa[i]/10;
			fa[i]%=10;
		}
		for(int i=400;i>=0;i--){
			ta[i]=ta[i]+tb[i]+c;
			c=ta[i]/10;
			ta[i]%=10;
		}

		int st=0;
		for(st=0;st<=400;st++){
			if(0!=ta[st]){
				break;
			}
		}
		int ed=400;
		for(;ed>=0;ed--){
			if(0!=fa[ed]){
				break;
			}
		}
		if(st>400 && ed<0){
			printf("0\n");
			continue;
		}
		if(st<=400){
			for(int i=st;i<=400;i++){
				printf("%d", ta[i]);
			}
		}
		if(ed>=0){
			printf(".");
			for(int i=0;i<=ed;i++){
				printf("%d", fa[i]);
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
