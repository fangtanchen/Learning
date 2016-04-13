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

struct CWord{
	char name[21];
	char fun[81];
};

struct CWord dict[100002];
int dict_len;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		freopen("out.txt","w",stdout);
	#endif
	
	char s[110];
	dict_len=0;
	char st;
	while(scanf("%c", &st)&&(st=='[')){
		scanf("%[^\]]%*c%*c", dict[dict_len].name);
		scanf("%[^\n]%*c", dict[dict_len].fun);
		dict_len++;
	}
	#ifdef U_DEBUG1
	for(int i=0;i<dict_len;i++){
		printf("%s:%s\n", dict[i].name, dict[i].fun);
	}
	#endif

	scanf("%[^\n]%*c", s);
	int T;
	for(scanf("%d%*c", &T);T--;){
		scanf("%[^\n]%*c", s);
		int i=0;

		if(s[0]=='['){
			s[strlen(s)-1]=0;
			for(i=0;i<dict_len;i++){
				if(!strcmp(s+1, dict[i].name)){
					printf("%s\n", dict[i].fun);
					break;
				}
			}
		}else{
			for(i=0;i<dict_len;i++)	{
				if(!strcmp(s, dict[i].fun)){
					printf("%s\n", dict[i].name);
					break;
				}
			}
		}
		if(i>=dict_len)printf("what?\n");
	}
	

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
