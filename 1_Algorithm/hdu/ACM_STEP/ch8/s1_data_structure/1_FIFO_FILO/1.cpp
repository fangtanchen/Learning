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
const int MAXN=1e5+10;

int Q[MAXN],qhead,qtail;
int S[MAXN],stop;

void Push(int x,int op){
    if(op==0){
        qtail=(qtail+1)%MAXN;
        Q[qtail]=x;
    }else{
        S[++stop]=x;
    }
}

void Pop(int op){
    if(0==op){
        if((qtail+1)%MAXN==qhead)printf("None\n");
        else{
            printf("%d\n",Q[qhead]);
            qhead=(qhead+1)%MAXN;
        }
    }else{
         if(stop<0)printf("None\n");
         else{
             printf("%d\n",S[stop]);
             stop=(stop-1);
         }
    }

}

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
//		freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
         stop=-1;
         qtail=-1;qhead=0;
         int N;
         char str[10];
         scanf("%d%s",&N,str);
         int op=(strcmp(str,"FIFO")==0?0:1);
         for(int i=0;i<N;i++){
             scanf("%s",str);
             if(strcmp(str,"IN")==0){
                 int x;
                 scanf("%d",&x);
                 Push(x,op);
             }else{
                  Pop(op);
             }
         }
    }

	#ifdef L_JUDGE
		fclose(stdin);
		fclose(stdout);
		system("out.txt");
	#endif

	return 0;
}
