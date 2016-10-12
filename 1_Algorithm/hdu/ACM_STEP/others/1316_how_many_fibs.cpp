#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

#define U_DEBUG
//#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
#define MAX_END 120

char f[2][205];
char sa[205], sb[205];
int len[2];
int si, di;
int cnt;


int init(){
	memset(f, '0', sizeof(f));
	memset(sa, '0', sizeof(sa));
	memset(sb, '0', sizeof(sb));
	len[0]=1;
	len[1]=1;
	si=0;
	di=1;
	f[si][120]='1';
	f[di][120]='2';
	sa[121]=sb[121]=f[si][121]=f[di][121]=0;
	cnt=0;
	return 0;
}


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	char a[200], b[200];
	while(scanf("%s %s", a, b), 
			strcmp(a, "0")||strcmp(b, "0")){
		init();
		int alen=strlen(a);
		int blen=strlen(b);
		strcpy(sa+MAX_END-alen+1, a);
		strcpy(sb+MAX_END-blen+1, b);
		
		while(strcmp(f[si], sa)<0){
			int c=0;
			for(int i=MAX_END;i>=0;i--){
				int temp=f[si][i]+f[di][i]-96+c;
				f[si][i]=temp%10+48;
				c=temp/10;
			}
			si=1-si;
			di=1-di;
		}
		while(strcmp(f[si], sb)<=0){
			cnt++;
			int c=0;
			for(int i=MAX_END;i>=0;i--){
				int temp=f[si][i]+f[di][i]-96+c;
				f[si][i]=temp%10+48;
				c=temp/10;
			}
			si=1-si;
			di=1-di;
		}
		printf("%d\n", cnt);
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
