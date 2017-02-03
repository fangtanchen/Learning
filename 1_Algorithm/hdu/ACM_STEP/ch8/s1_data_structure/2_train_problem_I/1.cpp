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

const int MAXN=10010;

char S[MAXN];
int slen;
int op[MAXN],oplen;
char A[100],B[100];
int N;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
        while(EOF!=scanf("%d%s%s",&N,A,B)){
             int i=0,j=0;
             slen=-1;
             oplen=0;
             while(A[i]){
                 S[++slen]=A[i];
                 op[oplen++]=0;
                 while((slen>=0)&&(S[slen]==B[j])){
                      slen--;j++;
                      op[oplen++]=1;
                 }
                 i++;
             }
             if(B[j]){
                  printf("No.\n");
             }else{
                 printf("Yes.\n");
                 for(int i=0;i<oplen;i++){
                     puts((op[i]?"out":"in"));
                 }
             }
             printf("FINISH\n");
        }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
