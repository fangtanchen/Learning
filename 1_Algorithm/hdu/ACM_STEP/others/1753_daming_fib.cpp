#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

#define MAX 401
char in_a[MAX];
char in_b[MAX];

char fa[MAX], fb[MAX];
char ia[MAX], ib[MAX];
char fans[MAX], ians[MAX];

int init(){
	memset(fa, 0, sizeof(fa));
	memset(fb, 0, sizeof(fb));
	memset(ia, 0, sizeof(ia));
	memset(ib, 0, sizeof(ib));
	memset(fans, 0, sizeof(fans));
	memset(ians, 0, sizeof(ians));
	return 0;
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	while(EOF!=scanf("%s %s", in_a, in_b)){
		#ifdef U_DEBUG
			printf("%s\n", in_a);
			printf("%s\n", in_b);
		#endif
		init();
		int pos_a=-1;
		int pos_b=-1;
		for(int i=strlen(in_a)-1;i>=0;i--){
			if(in_a[i]=='.'){
				pos_a=i;
				in_a[i]=' ';
				break;
			}
		}
		for(int i=strlen(in_b)-1;i>=0;i--){
			if('.'==in_b[i]){
				pos_b=i;
				in_b[i]=' ';
				break;
			}
		}
		if(pos_a>0){
			sscanf(in_a, "%s %s", ia, fa);
		}else if(pos_a==0){
			sscanf(in_a, "%s", fa);
		}else{
			sscanf(in_a, "%s", ia);
		}
		if(pos_b>0){
			sscanf(in_b, "%s %s", ib, fb);
		}if(pos_b==0){
			sscanf(in_b, "%s", fb);
		}else{
			sscanf(in_b, "%s", ib);
		}
		#ifdef U_DEBUG
				printf("%s:%s\n", ia, fa);
				printf("%s:%s\n\n", ib, fb);
		#endif
		//add float
		int s1=strlen(fa);
		int s2=strlen(fb);
		int c=0;
		for(int i=0;i<s1;i++){
			fans[i]=fa[i];
		}

		for(int i=s2-1;i>=0;i--){
			int temp=fans[i]+fb[i]+c-96;
			if(fans[i]==0)temp+=48;
			fans[i]=temp%10+'0';
			c=temp/10;
		}
		int maxlen=(s1>s2?s1:s2);
		for(;(maxlen>=0)&&('0'==fans[maxlen-1]);maxlen--)
			;

		//add integer
		s1=strlen(ia);
		s2=strlen(ib);
		int ians_len=0;
		int i=s1-1, j=s2-1;
		for(;i>=0&&j>=0;i--, j--){
			int temp=ia[i]+ib[j]+c-96;
			ians[ians_len++]=temp%10+48;
			c=temp/10;
		}
		while(j>=0){
			int temp=ib[j]+c-'0';
			ians[ians_len++]=temp%10+'0';
			c=temp/10;
			j--;
		}
		while(i>=0){
			int temp=ia[i]+c-'0';
			ians[ians_len++]=temp%10+'0';
			c=temp/10;
			i--;
		}
		while(c){
			ians[ians_len++]=c%10+'0';
			c/=10;
		}
		
		while(ians_len>0 &&(ians[ians_len-1]=='0')){
			ians_len--;
		}
		if(ians_len<=0 && (maxlen<=0)){
			printf("0\n");
			continue;
		}
		if(ians_len>0){
			int i=ians_len-1;
			for(;i>=0;i--){
				printf("%c", ians[i]);
			}
		}
		if(maxlen>0){
			printf(".");
			for(int i=0;i<maxlen;i++){
				printf("%c", fans[i]);
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
