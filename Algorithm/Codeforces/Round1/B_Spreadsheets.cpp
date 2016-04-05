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

bool IsDigit(char c){
	return (c>='0')&&(c<='9');
}

bool IsLetter(char c){
	return ((c>='A')&&(c<='Z'));
}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	int n;
	cin>>n;
	while(n--){
		char str[40];
		char a[4][40];
		int len[4]={0, 0, 0, 0};
		memset(a, 0, sizeof(a));
		cin>>str;
		int tp=0;
		int ll=strlen(str)-1;


		for(int i=0;i<ll;i++){
			if((IsLetter(str[i])&&IsDigit(str[i+1]))
				||(IsDigit(str[i])&&(IsLetter(str[i+1])))){
				a[tp][len[tp]++]=str[i];
				tp++;
				len[tp]=0;
				
			}else{
				a[tp][len[tp]++]=str[i];
			}
		}
		a[tp][len[tp]++]=str[ll];
		if(1==tp){
			printf("R%s", a[1]);
			int q=26;
			int num=0;
			for(int i=len[0]-2;i>=0;i--){
				num+=q;
				q*=26;
			}
			int temp=0;
			for(int i=0;i<len[0];i++){
				temp=temp*26+a[0][i]-'A';
			}
			printf("C%d\n", num+temp+1);
		}else{
			int q=26;
			int qi=0;
			int num=0;
			for(int i=0;i<len[3];i++){
				num=num*10+a[3][i]-'0';
			}
			num--;
			while(num>=q){
				num-=q;
				q*=26;
				qi++;
			}
			int kk[50];
			for(int i=0;i<=qi;i++){
				kk[i]=num%26;
				num/=26;
			}
			for(int i=qi;i>=0;i--){
				printf("%c", 'A'+kk[i]);
			}
			printf("%s\n", a[1]);
		}
	}

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
