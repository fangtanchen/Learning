#include<iostream>
#include<cstdio>
#include<cstring>
//#include<vector>
#include<algorithm>
#include<stack>
#include<queue>

#define U_DEBUG
#define L_JUDGE

#ifdef L_JUDGE
#pragma warning(disable:4996)
#endif

using namespace std;
stack<int> S;
queue<int> Q;

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int T;
    scanf("%d",&T);
    while(T--){
        while(!Q.empty())Q.pop();
        while(!S.empty())S.pop();
         int N;
         char str[10];
         scanf("%d%s",&N,str);
         if(strcmp(str,"FIFO")==0){
             while(N--){
                 scanf("%s",str);
                 if(strcmp(str,"IN")==0){
                     int x;
                     scanf("%d",&x);
                     Q.push(x);
                 }else{
                      if(Q.empty())printf("None\n");
                      else {
                          printf("%d\n",Q.front());
                          Q.pop();
                      }
                 }
             }
         }else{
             while(N--){
                 scanf("%s",str);
                 if(strcmp(str,"IN")==0){
                     int x;
                     scanf("%d",&x);
                     S.push(x);
                 }else{
                      if(S.empty())printf("None\n");
                      else {
                          printf("%d\n",S.top());
                          S.pop();
                      }
                 }
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
