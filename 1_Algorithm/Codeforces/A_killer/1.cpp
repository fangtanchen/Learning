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
const int MAXN=1005;

char name[2][30];
char tmp[2][30];
int n;


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%s%s",name[0],name[1]);
    scanf("%d",&n);
    printf("%s %s\n",name[0],name[1]);
    for(int i=1;i<=n;i++){
         scanf("%s%s",tmp[0],tmp[1]);
         if(strcmp(name[0],tmp[0])==0){
             strcpy(name[0],tmp[1]);
         }else{
             strcpy(name[1],tmp[1]);
         }
         printf("%s %s\n",name[0],name[1]);
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
