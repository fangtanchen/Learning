#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>

//#define U_DEBUG
///#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;

int get_next(int x){
	int a, b, n;
	char s[10];
	sprintf(s, "%d", x);
	n=strlen(s);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(s[i]>s[j]){
				char t=s[i];s[i]=s[j];s[j]=t;
			}
		}
	}
	sscanf(s, "%d", &b);
	for(int i=0;i<n/2;i++){
		char t=s[i];s[i]=s[n-1-i];s[n-1-i]=t;
	}
	sscanf(s, "%d", &a);
	return a-b;
}

int num[2000], cnt;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	scanf("%d", &num[0]);
	printf("%d", num[0]);
	cnt=1;
	for(;;){
		num[cnt]=get_next(num[cnt-1]);
		printf("-> %d", num[cnt]);
		int found=0;
		for(int i=0;i<cnt;i++){
			if(num[i]==num[cnt]){
				found=1;
				break;
			}
		}
		if(found)break;
		cnt++;
	}
	printf("\n");
	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
