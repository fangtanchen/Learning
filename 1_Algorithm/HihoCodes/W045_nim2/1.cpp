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
const int MAXN=10005;

int N;
int num[MAXN];
int len;
char s[MAXN];


int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    scanf("%d",&N);
    scanf("%s",s);
    len=1;
    int slen=strlen(s);
    for(int i=0;i<slen;i++){
        if(s[i]=='H'){
            num[len]=i+1;
            len++;
        }
    }
    int res=0;
    for(int i=1;i<len;i++){
        res^=num[i] ;
    }
    if(res){
        printf("Alice\n");
    }else{
         printf("Bob\n");
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
//		system("out.txt");
	#endif

	return 0;
}
