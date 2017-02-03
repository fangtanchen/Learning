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

int Q[4][11][2100];
int head[4][11],tail[4][11];

int main(){
	#ifdef L_JUDGE
		freopen("in.txt","r",stdin);
		//freopen("out.txt","w",stdout);
	#endif
    int N;
    while(EOF!=scanf("%d",&N)){
        memset(head,0,sizeof(head));
        memset(tail,-1,sizeof(tail));
        int no=0;
        while(N--){
            char cmd[20];
            int A,B;
            scanf("%s",cmd);
            if(strcmp(cmd,"IN")==0){
                no++;
                 scanf("%d%d",&A,&B);
                 Q[A][B][++tail[A][B]]=no;
            }else{
                 scanf("%d",&A);
                 bool flag=false;
                 for(int bi=10;bi>0;bi--){
                     if(head[A][bi]==tail[A][bi]+1)continue;
                     printf("%d\n",Q[A][bi][head[A][bi]++]);
                     flag=true;
                     break;
                 }
                 if(!flag)printf("EMPTY\n");
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
